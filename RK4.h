#ifndef RK4_H
#define RK4_H
#include "integrator.h"
// RK4 Integrator class - inherets from base class Iterator.
class RK4 : public Integrator {
    public:
        // Default destructor for forward euler integrator.
        virtual ~RK4() = default;

        // Step function for RK4 - takes one timestep and modifies the system state by the step.
        // args: System object passed by reference, timestep
        // return: void
        virtual void step(
            System& ODE, 
            double dt
        );
};
#endif