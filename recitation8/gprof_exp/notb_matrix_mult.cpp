#include <iostream>
#include <vector>

// Difference btween transpose or not becomes appearant with -march=native and -O1 flag
// Transpose the matrix can help with cache efficiency given the access parttern
void optimized_matrix_multiply_withouttranspose(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C) {
    int n = A.size();

    // Efficient matrix multiplication without transposing B
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];  // Direct multiplication without transposing B
            }
        }
    }
}

int main() {
    const int n = 1000;  // Size of matrix

    // Initialize matrices
    std::vector<std::vector<int>> A(n, std::vector<int>(n, 1));
    std::vector<std::vector<int>> B(n, std::vector<int>(n, 2));
    std::vector<std::vector<int>> C(n, std::vector<int>(n, 0));

    optimized_matrix_multiply_withouttranspose(A, B, C);

    return 0;
}
