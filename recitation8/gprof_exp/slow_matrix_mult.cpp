#include <iostream>
#include <vector>

// Correct but inefficient matrix multiplication
std::vector<std::vector<int>> inefficient_matrix_multiply(
    const std::vector<std::vector<int>>& A,
    const std::vector<std::vector<int>>& B) {

    int n = A.size();
    std::vector<std::vector<int>> C(n, std::vector<int>(n, 0));

    // Inefficient structure:
    // - recomputes transposed elements of B
    // - re-accesses memory in the worst cache order
    // - no prefetching or local caching
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                // Repeatedly fetch B[k][j] in a cache-unfriendly order
                // and perform direct accumulation
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

int main() {
    const int n = 300;  // Larger = slower demo
    std::vector<std::vector<int>> A(n, std::vector<int>(n, 1));
    std::vector<std::vector<int>> B(n, std::vector<int>(n, 2));

    std::cout << "Starting inefficient matrix multiply..." << std::endl;
    auto C = inefficient_matrix_multiply(A, B);
    std::cout << "Done. Result[0][0] = " << C[0][0] << std::endl;

    return 0;
}