#include "NewtonRaphsonSolver.h"
std::vector<double> NewtonRaphsonSolver(
    System& ODE, 
    std::vector<double> y0, 
    double dt,
    double tolerance, 
    int max_iters
) {
    // initialise y,t,n and y' as zeros or from the ODE system.
    std::vector<double> y = y0;
    double t = ODE.get_time();
    int n = y0.size();
    std::vector<double> dydt(n);

    // Initialise the jacobian matrix and the identity matrix as size nxn.
    std::vector<std::vector<double>> J(n, std::vector<double>(n));
    std::vector<std::vector<double>> I = eye<double>(n, n);

    // iterate for up to the maximum iterations allowed.
    for (int iter = 0; iter < max_iters; ++iter) {
        // obtain the state derivative and jacobian from the ODE system.
        ODE.f(y, t, dydt);
        ODE.jac(y, t, J);

        // define the residual functions.
        std::vector<double> f_val = y - y0 - dt * dydt;
        std::vector<std::vector<double>> j_val = I - (dt * J);

        // obtain the norm of the derivative.
        double norm = vector_norm(f_val);

        // if the norm is within tolerance then the system is cosidered solved so return the approximate root.
        if (norm < tolerance) {
            return y;
        }

        // if the norm is not small enough then solve the linear system to obtain an update for y.
        std::vector<double> dy = solve_linear_system(j_val, f_val);

        // if the y update is empty then the solver has failed so return an empty vector and report error to user.
        if (dy.empty()) {
            std::cerr << "Linear solver failed (singular matrix)." << std::endl;
            return {}; 
        }

        // update state for next iteration.
        y = y - dy;
    }
    return {};
};