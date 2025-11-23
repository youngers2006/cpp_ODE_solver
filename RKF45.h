#ifndef RKF45_H
#define RKF45_H
#include "integrator.h"
// RK4 Integrator class - inherets from base class Iterator.
class RKF45 : public Integrator {
    public:
        // Default destructor for forward euler integrator.
        virtual ~RKF45() = default;

        // Step function for RK4 - takes one timestep and modifies the system state by the step.
        // args: System object passed by reference, timestep
        // return: void
        virtual void step(
            System& ODE, 
            double dt
        );
};
#endif