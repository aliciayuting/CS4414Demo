#include <immintrin.h>   // AVX2/FMA intrinsics
#include <cstring>       // std::memset
#include <iostream>

// -------- Parameters --------
// Pick your matrix size here (known at compile time)
constexpr int N = 256;

// Optional: align to 32 bytes for nicer loads/stores
alignas(32) float A[N][N];
alignas(32) float B[N][N];
alignas(32) float C[N][N];

// Zero-initialize a matrix C (C-style array)
static inline void zero_matrix(float c[][N]) {
    // safe because the matrix is contiguous in row-major
    std::memset(c, 0, sizeof(float) * N * N);
}

void matmul_simd(const float a[][N], const float b[][N], float c[][N]) {
    zero_matrix(c);
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < N; ++k) {
            float aik = a[i][k];
            for (int j = 0; j < N; ++j) {
                c[i][j] += aik * b[k][j];
            }
        }
    }
}

int main() {
    // Example init: A = 1s, B = 2s
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < N; ++k) {
            A[i][k] = 1.0f;
            B[i][k] = 2.0f;
        }
    }

    matmul_simd(A, B, C);

    // Quick sanity check: expected C[i][j] = sum_k 1 * 2 = 2N
    std::cout << "C[0][0] = " << C[0][0] << " (expected " << 2 * N << ")\n";
    return 0;
}