#include <iostream>
#include <vector>

void optimized_matrix_multiply(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C) {
    int n = A.size();

    // Precompute the transposed matrix B_T only once for 
    std::vector<std::vector<int>> B_T(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            B_T[j][i] = B[i][j];  
        }
    }

    // Efficient matrix multiplication
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B_T[j][k];  // No unnecessary recomputation
            }
        }
    }
}

int main() {
    const int n = 1000;  

    // Initialize matrices
    std::vector<std::vector<int>> A(n, std::vector<int>(n, 1));
    std::vector<std::vector<int>> B(n, std::vector<int>(n, 2));
    std::vector<std::vector<int>> C(n, std::vector<int>(n, 0));

    // Time the optimized matrix multiplication
    optimized_matrix_multiply(A, B, C);

    return 0;
}
