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