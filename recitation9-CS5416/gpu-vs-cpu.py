import torch
import time

def matmul_tensors(tensor_a, tensor_b):
    # do it using python loops
    result = torch.zeros(tensor_a.size(0), tensor_b.size(1))
    for i in range(tensor_a.size(0)):
        for j in range(tensor_b.size(1)):
            for k in range(tensor_a.size(1)):
                result[i, j] += tensor_a[i, k] * tensor_b[k, j]
    return result


if __name__ == "__main__":
    n = 4096
    a = torch.randn(n, n)
    b = torch.randn(n, n)
    result = b @ a
    start = time.time()
    result = a @ b
    end = time.time()
    print(f"Time taken for matrix multiplication: {(end - start)*1000000} us")
    print(result.shape)


    a = a.to('mps')
    b = b.to('mps')
    result = b @ a
    torch.mps.synchronize()
    start = time.time()
    result = a @ b
    torch.mps.synchronize()
    end = time.time()
    print(f"Time taken for matrix multiplication on MPS: {(end - start)*1000000} us")
    print(result.shape)
    
    # start = time.time()
    # result = matmul_tensors(a, b)
    # end = time.time()
    # print(f"Time taken for custom matrix multiplication: {(end - start)*1000000} us")
