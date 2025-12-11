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
    std::vector<std::vector<double>> I = eye(n, n);
    for (int iter = 0; iter < max_iters; ++iter) {
        std::vector<double> dydt;
        std::vector<std::vector<double>> J(n, std::vector<double>(n, 0.0));
        ODE.f(y, t, dydt);
        ODE.jac(y, t, J);
        std::vector<double> f_val = y - y0 - dt * dydt;
        std::vector<std::vector<double>> j_val = I - (dt * J);
        double norm = vector_norm(dydt);
        if (norm < tolerance) {
            return y;
        }
        std::vector<double> dy = solve_linear_system(j_val, f_val);
        y = y - dy;
    }
    std::cerr << "Newton Raphson Solver failed to converge at time: " << t << std::endl;
    return {};
};