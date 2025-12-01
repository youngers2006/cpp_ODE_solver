#ifndef SATELITE_ATTITUDE_DYNAMICS_H
#define SATELITE_ATTITUDE_DYNAMICS_H
#include "system.h"
class Satelite_dynamicsODE : public System {
    public:
        // ODE user defined constructor.
        // args: parameters, initial conditions, initial time.
        Satelite_dynamicsODE(
            const std::vector<double>& params, 
            const std::vector<double>& ics, 
            const double& itime
        );

        // virtual evaluation function for ODE.
        // args: state vector, time, state derivative vector.
        // return: void. Derivative vector edited in-place.
        virtual void f(
            const std::vector<double>& y, 
            double& t, 
            std::vector<double>& dydt
        );

        virtual void jac(
            const std::vector<double>& y,
            double t,
            std::vector<std::vector<double>>& jac
        ) = 0;
};
#endif