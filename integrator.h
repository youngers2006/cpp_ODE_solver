#ifndef INTEGRATOR_H
#define INTEGRATOR_H
#include "system.h"
#include "vector_math_templates.h"
// Base class for all Integration methods.
// Class variables: void
// Class methods: default destructor (virtual), step function (virtual)
class Integrator {
    public: 
        // Default destructor for Integrator.
        virtual ~Integrator() = default;

        // Step function for Integrator - takes one timestep and modifies the system state by the step.
        // args: System object passed by reference, timestep
        // return: void
        virtual void step(
            System& ODE, 
            double dt
        ) = 0;
};
#endif