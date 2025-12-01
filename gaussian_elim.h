#ifndef GAUSSIAN_ELIM_H
#define GAUSSIAN_ELIM_H
#include <cmath>
#include <vector>
#include <iostream>

std::vector<double> solve_linear_system(std::vector<std::vector<double>> A, std::vector<double> b) {
    int n = A.size(); // Number of rows/variables

    // Forward Elimination with Partial Pivoting
    for (int i = 0; i < n; ++i) {
        
        // Find pivot (row with largest absolute value in the current column i)
        int max_row = i;
        for (int k = i + 1; k < n; ++k) {
            if (std::abs(A[k][i]) > std::abs(A[max_row][i])) {
                max_row = k;
            }
        }
        
        // Swap rows in A and b to bring the largest pivot element to the diagonal
        if (max_row != i) {
            std::swap(A[i], A[max_row]);
            std::swap(b[i], b[max_row]);
        }

        // Check for singular matrix (division by zero pivot)
        if (std::abs(A[i][i]) < 1e-12) {
            std::cerr << "Error: Jacobian is near singular (cannot solve)." << std::endl;
            return {}; // Return empty vector indicating failure
        }

        // Eliminate
        for (int k = i + 1; k < n; ++k) {
            double factor = A[k][i] / A[i][i];
            
            // Modify row k: A[k] = A[k] - factor * A[i]
            for (int j = i; j < n; ++j) {
                A[k][j] -= factor * A[i][j];
            }
            // Modify RHS: b[k] = b[k] - factor * b[i]
            b[k] -= factor * b[i];
        }
    }

    // Back Substitution
    std::vector<double> x(n);
    for (int i = n - 1; i >= 0; --i) {
        double sum = 0.0;
        // Sum the known terms (A[i][j] * x[j])
        for (int j = i + 1; j < n; ++j) {
            sum += A[i][j] * x[j];
        }
        // Solve for the current variable x[i]
        x[i] = (b[i] - sum) / A[i][i];
    }

    return x;
}
#endif