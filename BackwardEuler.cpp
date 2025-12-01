#include "BackwardEuler.h"
void BackwardEuler::step(System& ODE, double dt) {
    // Get current state and time and initialise the state derivative vector.
    std::vector<double> y = ODE.get_state();
    std::vector<double> dydt(y.size());
    double t = ODE.get_time();

    
    

    ODE.set_time(t + dt);
    ODE.set_state(y_);
};