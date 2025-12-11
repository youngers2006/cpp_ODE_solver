#include "NewtonRaphsonSolver.h"
std::vector<double> NewtonRaphsonSolver(
    System& ODE, 
    std::vector<double> y0, 
    double dt,
    double tolerance = 1e-9, 
    int max_iters = 50
) {
    std::vector<double> y = y0;
    double t = ODE.get_time();
    int n = y0.size();
    std::vector<double> dydt(n);
    std::vector<std::vector<double>> J(n, std::vector<double>(n));
    std::vector<std::vector<double>> I = eye(n, n);
    for (int iter = 0; iter < max_iters; ++iter) {
        ODE.f(y, t, dydt);
        ODE.jac(y, t, J);
        std::vector<double> f_val = y - y0 - dt * dydt;
        std::vector<std::vector<double>> j_val = I - (dt * J);
        double norm = vector_norm(dydt);
        if (norm < tolerance) {
            return y;
        }
        std::vector<double> dy = solve_linear_system(j_val, f_val);
        if (dy.empty()) {
            std::cerr << "Linear solver failed (singular matrix)." << std::endl;
            return {}; 
        }
        y = y - dy;
    }
    return {};
};