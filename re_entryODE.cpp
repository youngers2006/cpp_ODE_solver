#include <vector>
#include <cmath>
#include "re_entryODE.h"

re_entry_ODE::re_entry_ODE(const std::vector<double>& params, 
                           const std::vector<double>& ics, 
                           const double& itime) : System(params, ics, itime) {};

void re_entry_ODE::f(
            const std::vector<double>& y, // y = [h, v, gamma]
            double& t, 
            std::vector<double>& dydt) { // dydt = [h_, v_, gamma_], parameters = [rho0, Cl, Cd, m, g, A]
                double rho = parameters[0] * exp(-y[0] / 7200.0);
                double L = (1.0 / 2.0) * rho * parameters[5] * parameters[1] * pow(y[1],2);
                double D = (1.0 / 2.0) * rho * parameters[5] * parameters[2] * pow(y[1],2);
                double h_ = - y[1] * sin((3.1415 / 180) * y[2]);
                double v_ = - (D / parameters[3]) - parameters[4] * sin((3.1415 / 180) * y[2]);
                double gamma_ = (L / (parameters[3] * y[1])) - (parameters[4] / y[1]) * cos((3.1415 / 180) * y[2]);
                dydt[0] = h_;
                dydt[1] = v_;
                dydt[2] = gamma_;
};

void re_entry_ODE::jac(
            const std::vector<double>& y,
            double t,
            std::vector<std::vector<double>>& jac
        ) {
            double h = y[0];
            double v = y[1];
            double gamma = y[2];

            double rho0 = parameters[0];
            double Cl = parameters[1];
            double Cd = parameters[2];
            double m = parameters[3];
            double g = parameters[4];
            double A = parameters[5];

            jac[0][0] = 0;
            jac[0][1] = - sin((3.1415 / 180) * gamma);
            jac[0][2] = - v * cos((3.1415 / 180) * gamma);

            jac[1][0] = (rho0 * pow(v,2) * Cd * A * exp(-h / 7200.0)) / (2 * 7200.0 * m);
            jac[1][1] = (rho0 * Cd * A * v * exp(-h / 7200.0)) / m;
            jac[1][2] = -g * cos((3.1415 / 180) * gamma);

            jac[2][0] = (-rho0 * Cd * A * exp(-h / 7200)) / (2 * 7200 * m);
            jac[2][1] = ((rho0 * A * Cd * exp(-h / 7200)) / (2 * m)) + ((g * cos((3.1415 / 180) * gamma)) / pow(v, 2));
            jac[2][2] = (g / v) * sin((3.1415 / 180) * gamma);
};