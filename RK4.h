#ifndef RK4_H
#define RK4_H
#include "integrator.h"
class RK4 : public Integrator {
    public:
        virtual ~RK4() = default;
        virtual void step(
            System& ODE, 
            double& dt
        );
};
#endif