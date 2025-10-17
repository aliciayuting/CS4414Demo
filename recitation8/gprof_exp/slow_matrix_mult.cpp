#include <iostream>
#include <vector>

std::vector<std::vector<int>> inefficient_matrix_multiply(
    std::vector<std::vector<int>> A,
    std::vector<std::vector<int>> B) {

    int n = A.size();
    std::vector<std::vector<int>> C(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

int main() {
    const int n = 300;  
    std::vector<std::vector<int>> A(n, std::vector<int>(n, 1));
    std::vector<std::vector<int>> B(n, std::vector<int>(n, 2));

    // std::cout << "Starting inefficient matrix multiply..." << std::endl;
    auto C = inefficient_matrix_multiply(A, B);
    // std::cout << "Done. Result[0][0] = " << C[0][0] << std::endl;

    return 0;
}