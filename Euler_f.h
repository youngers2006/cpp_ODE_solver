#ifndef EULER_F_H
#define EULER_F_H
#include "integrator.h"
class Euler_f : public Integrator {
    public:
        virtual ~Euler_f() = default;
        virtual void step(System& ODE, double dt);
};
#endif