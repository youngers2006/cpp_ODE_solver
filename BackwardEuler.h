#ifndef BACKWARDEULER_H
#define BACKWARDEULER_H
#include "integrator.h"
#include "NewtonRaphsonSolver.h"
// RK4 Integrator class - inherets from base class Iterator.
class BackwardEuler : public Integrator {
    public:
        // Default destructor for forward euler integrator.
        virtual ~BackwardEuler() = default;

        // Step function for RK4 - takes one timestep and modifies the system state by the step.
        // args: System object passed by reference, timestep
        // return: void
        virtual void step(
            System& ODE, 
            double dt
        );
};
#endif