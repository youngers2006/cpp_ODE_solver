#ifndef ROTATIONAL_DYNAMICS.H
#define ROTATIONAL_DYNAMICS.H
#include "system.h"
class RotationalDynamicsODE : public System {
    public:
        RotationalDynamicsODE(
            const std::vector<double>& params, 
            const std::vector<double>& ics, 
            const double& itime
        );
        virtual void f(
            const std::vector<double>& y, 
            double& t, 
            std::vector<double>& dydt
        );
};
#endif