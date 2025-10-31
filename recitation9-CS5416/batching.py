import time
import math
import torch
import torch.nn as nn

# ---------------------------
# Utilities
# ---------------------------
def get_device():
    if torch.backends.mps.is_available():
        return torch.device("mps")
    return torch.device("cpu")

def sync(device):
    # Ensure we measure real elapsed time on async backends
    if device.type == "mps":
        torch.mps.synchronize()
    elif device.type == "cuda":
        torch.cuda.synchronize()

def fmt_us(seconds):
    return f"{seconds * 1e6:.1f} µs"

def fmt_ms(seconds):
    return f"{seconds * 1e3:.3f} ms"

# Warmup helper (important for fair timing)
def warmup(fn, iters=10):
    for _ in range(iters):
        fn()

# ---------------------------
# 1) Tiny GEMM: unbatched vs batched
# ---------------------------
def gemm_unbatched(n=64, reps=4096, device=None, dtype=torch.float32):
    if device is None:
        device = get_device()
    a = torch.randn(n, n, device=device, dtype=dtype)
    b = torch.randn(n, n, device=device, dtype=dtype)

    # One multiply to trigger any just-in-time compilation / caching
    _ = a @ b
    sync(device)

    def body():
        x = a
        y = b
        for _ in range(reps):
            _ = x @ y

    warmup(body, 5)
    t0 = time.perf_counter()
    body()
    sync(device)
    t1 = time.perf_counter()
    return (t1 - t0) / reps  # average per matmul

def gemm_batched(n=64, batch=256, steps=16, device=None, dtype=torch.float32):
    if device is None:
        device = get_device()
    
    A = torch.randn(batch, n, n, device=device, dtype=dtype)
    B = torch.randn(batch, n, n, device=device, dtype=dtype)

    # One batched multiply to warm caches/compile
    _ = torch.bmm(A, B)
    sync(device)

    def body():
        X = A
        Y = B
        for _ in range(steps):
            # shape: (B, n, n) x (B, n, n) -> (B, n, n)
            _ = torch.bmm(X, Y)

    warmup(body, 5)
    t0 = time.perf_counter()
    body()
    sync(device)
    t1 = time.perf_counter()
    total_matmuls = batch * steps
    return (t1 - t0) / total_matmuls  # average per matmul-equivalent

# ---------------------------
# 2) Tiny MLP: per-sample loop vs batched forward
# ---------------------------
class TinyMLP(nn.Module):
    def __init__(self, d_in=256, d_hidden=512, d_out=128):
        super().__init__()
        self.net = nn.Sequential(
            nn.Linear(d_in, d_hidden),
            nn.GELU(),
            nn.Linear(d_hidden, d_out),
        )

    def forward(self, x):
        return self.net(x)

@torch.inference_mode()
def mlp_unbatched(model, batch=1024, d_in=256, device=None, dtype=torch.float32):
    if device is None:
        device = get_device()
    # per-sample loop (bad): many tiny kernels & Python overhead
    def body():
        out_sum = 0.0
        for _ in range(batch):
            x = torch.randn(1, d_in, device=device, dtype=dtype)
            y = model(x)
            out_sum += float(y.mean())
        return out_sum

    # Warmup
    warmup(body, 2)
    t0 = time.perf_counter()
    _ = body()
    sync(device)
    t1 = time.perf_counter()
    return (t1 - t0) / batch

@torch.inference_mode()
def mlp_batched(model, batch=1024, d_in=256, device=None, dtype=torch.float32):
    if device is None:
        device = get_device()
    X = torch.randn(batch, d_in, device=device, dtype=dtype)

    # One forward to warm up
    _ = model(X)
    sync(device)

    def body():
        Y = model(X)
        return float(Y.mean())

    warmup(body, 5)
    t0 = time.perf_counter()
    _ = body()
    sync(device)
    t1 = time.perf_counter()
    return (t1 - t0) / batch

# ---------------------------
# Demo driver
# ---------------------------
def main():
    device = get_device()
    print(f"Device: {device}")

    # ---- Part 1: GEMM vs Batched GEMM ----
    n = 64
    total_ops = 4096             # total independent 64x64 matmuls
    batch = 256
    steps = total_ops // batch   # 16 steps of batched bmm

    t_unbatched = gemm_unbatched(n=n, reps=total_ops, device=device)
    t_batched   = gemm_batched(n=n, batch=batch, steps=steps, device=device)

    print("\n=== Tiny GEMM (64x64) ===")
    print(f"Unbatched avg per-matmul: {fmt_us(t_unbatched)}")
    print(f"Batched   avg per-matmul: {fmt_us(t_batched)}")
    speedup = t_unbatched / t_batched
    print(f"Throughput gain (per-matmul): {speedup:.2f}×")

    # ---- Part 2: Tiny MLP ----
    d_in, d_hidden, d_out = 256, 512, 128
    B = 2048  # total samples

    model = TinyMLP(d_in, d_hidden, d_out).to(device)
    # make deterministic-ish
    torch.manual_seed(0)
    #exit(0)
    t_mlp_unbatched = mlp_unbatched(model, batch=B, d_in=d_in, device=device)
    t_mlp_batched   = mlp_batched(model, batch=B, d_in=d_in, device=device)

    print("\n=== Tiny MLP (Linear->GELU->Linear) ===")
    print(f"Per-sample loop avg time: {fmt_us(t_mlp_unbatched)}")
    print(f"Batched forward  avg time: {fmt_us(t_mlp_batched)}")
    print(f"Throughput gain (per-sample): {t_mlp_unbatched / t_mlp_batched:.2f}×")

    #exit(0)
    # Optional: “latency vs batch size” sweep for classroom discussion
    print("\n=== Batch size sweep (MLP, avg time per sample) ===")
    for B in [1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576]:
        X = torch.randn(B, d_in, device=device, dtype=torch.float32)
        # warm
        _ = model(X); sync(device)
        t0 = time.perf_counter()
        _ = model(X); sync(device)
        t1 = time.perf_counter()
        per_sample = (t1 - t0) / B
        print(f"B={B:4d}: {fmt_us(per_sample)} per sample")

if __name__ == "__main__":
    main()
