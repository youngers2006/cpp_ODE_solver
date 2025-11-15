#include <vector>
#include "Euler_f.h"
void Euler_f::step(System& ODE, double dt) {
    std::vector<double> dydt;
    std::vector<double> y = ODE.get_state();
    double t = ODE.get_time();
    ODE.f(y, t, dydt);
    std::vector<double> y_ = y + dydt * dt; // define * for vectors later
    ODE.set_state(y_);
    ODE.set_time(t + dt);
};