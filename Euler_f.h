#ifndef EULER_F_H
#define EULER_F_H
#include "integrator.h"
// Euler Integrator class - inherets from base class Iterator.
class Euler_f : public Integrator {
    public:
        // Default destructor for forward euler integrator.
        virtual ~Euler_f() = default;

        // Step function for forwards Euler - takes one timestep and modifies the system state by the step.
        // args: System object passed by reference, timestep
        // return: void
        virtual void step(
            System& ODE, 
            double dt
        );
};
#endif