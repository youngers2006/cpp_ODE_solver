#include <vector>
#include <cmath>
#include "re_entryODE.h"

re_entry_ODE::re_entry_ODE(const std::vector<double>& params, 
                           const std::vector<double>& ics, 
                           const double& itime) : System(params, ics, itime) {};

void re_entry_ODE::f(
            const std::vector<double>& y, // y = [h, v, gamma]
            double& t, 
            std::vector<double>& dydt) { // dydt = [h_, v_, gamma_], parameters = [rho0, Cl, Cd, m, g]
                double rho = parameters[0] * exp(-y[0]);
                double L = (1.0 / 2.0) * rho * parameters[1] * pow(y[1],2);
                double D = (1.0 / 2.0) * rho * parameters[2] * pow(y[1],2);
                double h_ = - y[1] * sin((3.1415 / 180) * y[2]);
                double v_ = - (D / parameters[3]) - parameters[4] * sin(y[2]);
                double gamma_ = (L / (parameters[3] * y[1])) - (parameters[4] / y[1]) * cos(y[2]);
                dydt[0] = h_;
                dydt[1] = v_;
                dydt[2] = gamma_;
};