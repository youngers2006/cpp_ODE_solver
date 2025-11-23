#include "rotational_dynamics.h"

RotationalDynamicsODE::RotationalDynamicsODE(
    const std::vector<double>& params, 
    const std::vector<double>& ics, 
    const double& itime) : System(params, ics, itime) {};

void RotationalDynamicsODE::f(const std::vector<double>& y, double& t, std::vector<double>& dydt) { // y = [wx, wy, wz], params = [Ix, Iy, Iz, tau_x, tau_y, tau_z]
    double wx_ = ((parameters[1] - parameters[2]) * y[1] * y[2] + parameters[3]) / parameters[0];
    double wy_ = ((parameters[2] - parameters[0]) * y[2] * y[0] + parameters[4]) / parameters[1];
    double wz_ = ((parameters[0] - parameters[1]) * y[0] * y[1] + parameters[5]) / parameters[2];
    dydt[0] = wx_;
    dydt[1] = wy_;
    dydt[2] = wz_;
};