#include "satelite_attitude_dynamicsODE.h"
Satelite_dynamicsODE::Satelite_dynamicsODE(
    const std::vector<double>& params, 
    const std::vector<double>& ics, 
    const double& itime) : System(params, ics, itime) {};

void Satelite_dynamicsODE::f(const std::vector<double>& y, double& t, std::vector<double>& dydt) { // y = [wx, wy, wz], params = [Ix, Iy, Iz]
    double wx_ = ((parameters[1] - parameters[2]) / parameters[0]) * y[1] * y[2];
    double wy_ = ((parameters[2] - parameters[0]) / parameters[1]) * y[2] * y[0];
    double wz_ = ((parameters[0] - parameters[1]) / parameters[2]) * y[0] * y[1];
    dydt[0] = wx_;
    dydt[1] = wy_;
    dydt[2] = wz_;
};

void Satelite_dynamicsODE::jac(const std::vector<double>& y, double t, std::vector<std::vector<double>>& jac) {
    jac[0][0] = 0;
    jac[0][1] = ((parameters[1] - parameters[2]) / parameters[0]) * y[2];
    jac[0][2] = ((parameters[1] - parameters[2]) / parameters[0]) * y[1];
    jac[1][0] = ((parameters[2] - parameters[0]) / parameters[1]) * y[2];
    jac[1][1] = 0;
    jac[1][2] = ((parameters[2] - parameters[0]) / parameters[1]) * y[0];
    jac[2][0] = ((parameters[0] - parameters[1]) / parameters[2]) * y[1];
    jac[2][1] = ((parameters[0] - parameters[1]) / parameters[2]) * y[0];
    jac[2][2] = 0;
}