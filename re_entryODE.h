#ifndef RE_ENTRYODE_H
#define RE_ENTRYODE_H
#include <vector>
#include "system.h"
class re_entry_ODE : public System {
    public:
        // ODE user defined constructor.
        // args: parameters, initial conditions, initial time.
        re_entry_ODE(
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

        // virtual jacobian function for ODE.
        // args: state vector, time, state derivative vector.
        // return: void. Derivative vector edited in-place.
        virtual void jac(
            const std::vector<double>& y,
            double t,
            std::vector<std::vector<double>>& jac
        );
};
#endif