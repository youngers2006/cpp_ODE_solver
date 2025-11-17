#ifndef INTEGRATOR_H
#define INTEGRATOR_H
#include "system.h"
#include "vector_math_templates.h"
class Integrator {
    public:
        virtual ~Integrator() = default; // Destructor for the class
        virtual void step(
            System& ODE, 
            double dt
        ) = 0;
};
#endif