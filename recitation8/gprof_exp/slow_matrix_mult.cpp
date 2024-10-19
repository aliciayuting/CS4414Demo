#include <iostream>
#include <vector>


std::vector<std::vector<int>> inefficient_matrix_multiply(const std::vector<std::vector<int>> A, const std::vector<std::vector<int>> B) {
    int n = A.size();
    std::vector<std::vector<int>> C(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;
            // Duplicated, inefficient inner loop with unnecessary computations
            for (int k = 0; k < n; ++k) {
                // Inefficient: recompute the sum of row A[i] in every iteration of inner loop
                int row_sum = 0;
                for (int m = 0; m < n; ++m) {
                    row_sum += A[i][m];
                }

                // Multiply A[i][k] with B[k][j] and multiply by row_sum unnecessarily
                C[i][j] += A[i][k] * B[k][j] * row_sum;  // The row_sum multiplication is redundant
            }
        }
    }
    return C;
}

int main() {
    const int n = 200;  // Size of matrix 

    // Initialize matrices
    std::vector<std::vector<int>> A(n, std::vector<int>(n, 1));
    std::vector<std::vector<int>> B(n, std::vector<int>(n, 2));
    

    std::vector<std::vector<int>> C = inefficient_matrix_multiply(A, B);

    return 0;
}
