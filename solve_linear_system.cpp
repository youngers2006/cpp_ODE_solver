#include "solve_linear_system.h"
std::vector<double> solve_linear_system(
    std::vector<std::vector<double>> A, 
    std::vector<double> b
) {
    // initialise the number of rows
    int n = A.size(); 

    // forward elimination with partial pivoting.
    for (int i = 0; i < n; ++i) {
        
        // find the pivot row
        int max_row = i;
        for (int k = i + 1; k < n; ++k) {
            if (std::abs(A[k][i]) > std::abs(A[max_row][i])) {
                max_row = k;
            }
        }
        
        // swap rows in A and b to bring the largest pivot element to the diagonal.
        if (max_row != i) {
            std::swap(A[i], A[max_row]);
            std::swap(b[i], b[max_row]);
        }

        // check to ensure the jacobian is not singular, if it is, return an empty vector and notify the user.
        if (std::abs(A[i][i]) < 1e-12) {
            std::cerr << "Error: Jacobian is near singular (cannot solve)." << std::endl;
            return {};
        }

        // elimination step
        for (int k = i + 1; k < n; ++k) {
            double factor = A[k][i] / A[i][i];
            
            // modify the kth row.
            for (int j = i; j < n; ++j) {
                A[k][j] -= factor * A[i][j];
            }
            // modify the right hand side.
            b[k] -= factor * b[i];
        }
    }

    // back substitution steps.
    std::vector<double> x(n);
    for (int i = n - 1; i >= 0; --i) {
        double sum = 0.0;
        // sum known terms.
        for (int j = i + 1; j < n; ++j) {
            sum += A[i][j] * x[j];
        }
        // solve for the current variable.
        x[i] = (b[i] - sum) / A[i][i];
    }

    return x;
};