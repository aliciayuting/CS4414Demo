#include <iostream>
#include <vector>

// Compute dot product of two 1D vectors (copies by value)
int compute_cell(std::vector<int> rowA, std::vector<int> colB) {
    int n = rowA.size();
    int value = 0;
    for (int k = 0; k < n; ++k) {
        value += rowA[k] * colB[k];
    }
    return value;
}

// Compute one row of result matrix
std::vector<int> compute_row(
    std::vector<std::vector<int>> A,
    std::vector<std::vector<int>> B,
    int i)
{
    int n = A.size();
    std::vector<int> rowC(n, 0);

    // Extract row i of A once (by value makes it worse)
    std::vector<int> rowA = A[i];

    for (int j = 0; j < n; ++j) {
        // Build column j of B each time
        std::vector<int> colB(n);
        for (int k = 0; k < n; ++k) {
            colB[k] = B[k][j];
        }

        // Compute cell using two 1D vector copies
        rowC[j] = compute_cell(rowA, colB);
    }

    return rowC;
}

// Full matrix multiply
std::vector<std::vector<int>> ultra_inefficient_matrix_multiply(
    std::vector<std::vector<int>> A,
    std::vector<std::vector<int>> B)
{
    int n = A.size();
    std::vector<std::vector<int>> C(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        C[i] = compute_row(A, B, i);
    }

    return C;
}

int main() {
    const int n = 300;
    std::vector<std::vector<int>> A(n, std::vector<int>(n, 1));
    std::vector<std::vector<int>> B(n, std::vector<int>(n, 2));

    auto C = ultra_inefficient_matrix_multiply(A, B);
    // std::cout << "Done. Result[0][0] = " << C[0][0] << std::endl;
    return 0;
}