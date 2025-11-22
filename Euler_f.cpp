#include <vector>
#include "Euler_f.h"
void Euler_f::step(System& ODE, double dt) {
    // define derivative vector and obtain current state vector and current time from the system object.
    std::vector<double> y = ODE.get_state();
    std::vector<double> dydt(y.size()); 
    double t = ODE.get_time();

    // Obtain derivative vector from system class method.
    ODE.f(y, t, dydt);

    // Using vector operation templates use forward euler integration to obtain y_t+1.
    std::vector<double> y_ = y + dydt * dt;

    // Set the state and time of the ODE system to t+1.
    ODE.set_state(y_);
    ODE.set_time(t + dt);
};