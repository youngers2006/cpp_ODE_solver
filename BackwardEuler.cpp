#include "BackwardEuler.h"
void BackwardEuler::step(System& ODE, double dt) {
    // Get current state and time and initialise the state derivative vector.
    std::vector<double> y = ODE.get_state();
    double t = ODE.get_time();
    std::vector<double> y_ = NewtonRaphsonSolver(
        ODE, 
        y, 
        dt, 
        1e-9, 
        40
    );
    ODE.set_time(t + dt);
    ODE.set_state(y_);
};