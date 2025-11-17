#ifndef SATELITE_ATTITUDE_DYNAMICS_H
#define SATELITE_ATTITUDE_DYNAMICS_H
#include "system.h"
class Satelite_dynamicsODE : public System {
    public:
        Satelite_dynamicsODE(
            const std::vector<double>& params, 
            const std::vector<double>& ics, 
            const double& itime
        );
        virtual void f(
            std::vector<double> y, 
            double t, 
            std::vector<double> dydt
        );
};
#endif