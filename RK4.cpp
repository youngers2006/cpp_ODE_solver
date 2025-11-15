#include "RK4.h"
void RK4::step(System& ODE, double& dt) {
    std::vector<double> dydt;
    std::vector<double> y = ODE.get_state();
    double t = ODE.get_time();
    ODE.f(y, t, dydt);
    std::vector<double> K1 = dydt * dt;
    ODE.f(y + 0.5 * K1, t + 0.5 * dt, dydt);
    std::vector<double> K2 = dydt * dt;
    ODE.f(y + 0.5 * K2, t + 0.5 * dt, dydt);
    std::vector<double> K3 = dydt * dt;
    ODE.f(y + 0.5 * K3, t + dt, dydt);
    std::vector<double> K4 = dydt * dt;
    std::vector<double> y_ = y + (1.0/6.0) * K1 + (1.0/3.0) * (K2 + K3) + (1.0/6.0) * K4;
    ODE.set_time(t + dt);
    ODE.set_state(y_);
};