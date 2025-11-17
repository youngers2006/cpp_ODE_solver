#include <iostream>
#include <vector>
#include "system.h"

class Integrator {
    public:
        virtual ~Integrator() = default; // Destructor for the class
        virtual std::vector<double> step(
            System& ODE, 
            double dt
        ) = 0;
};