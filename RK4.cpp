#include "RK4.h"
void RK4::step(System& ODE, double dt) {
    std::vector<double> y = ODE.get_state();
    std::vector<double> dydt(y.size());
    double t = ODE.get_time();

    ODE.f(y, t, dydt);
    std::vector<double> K1 = dydt * dt;

    std::vector<double> y_k2 = y + 0.5 * K1;
    double t_k2 = t + 0.5 * dt;
    ODE.f(y_k2, t_k2, dydt);
    std::vector<double> K2 = dydt * dt;

    std::vector<double> y_k3 = y + 0.5 * K2;
    double t_k3 = t + 0.5 * dt;
    ODE.f(y_k3, t_k3, dydt);
    std::vector<double> K3 = dydt * dt;

    std::vector<double> y_k4 = y + 0.5 * K3;
    double t_k4 = t + 0.5 * dt;
    ODE.f(y_k4, t_k4, dydt);
    std::vector<double> K4 = dydt * dt;

    std::vector<double> y_ = y + (1.0/6.0) * K1 + (1.0/3.0) * (K2 + K3) + (1.0/6.0) * K4;
    ODE.set_time(t + dt);
    ODE.set_state(y_);
};