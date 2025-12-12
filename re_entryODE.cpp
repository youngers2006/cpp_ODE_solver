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
                double deg_to_rad = 3.14159265 / 180.0;
                double rad_to_deg = 180.0 / 3.14159265;
                
                double h = y[0];
                double v = y[1];
                double gamma_deg = y[2];
                double gamma_rad = gamma_deg * deg_to_rad;
                double rho = parameters[0] * exp(-h / 7200.0);
                double dyn_p = 0.5 * rho * parameters[5] * pow(v, 2);
                double L = dyn_p * parameters[1];
                double D = dyn_p * parameters[2];
                double h_ = -v * sin(gamma_rad);
                double v_ = -(D / parameters[3]) + parameters[4] * sin(gamma_rad);
                double gamma_dot_rad = (L / (parameters[3] * v)) + (parameters[4] / v) * cos(gamma_rad);
                double gamma_ = gamma_dot_rad * rad_to_deg;

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
            double gamma_deg = y[2];

            double PI = 3.14159265;
            double deg_to_rad = PI / 180.0;
            double rad_to_deg = 180.0 / PI;
            double gamma_rad = gamma_deg * deg_to_rad;

            double rho0 = parameters[0];
            double Cl = parameters[1];
            double Cd = parameters[2];
            double m = parameters[3];
            double g = parameters[4];
            double S = parameters[5]; 
            double H = 7200.0; 

            double rho = rho0 * exp(-h / H);
            double dyn_p = 0.5 * rho * S * pow(v, 2);
            double L = Cl * dyn_p;
            double D = Cd * dyn_p;

            jac[0][0] = 0.0;                                        
            jac[0][1] = -sin(gamma_rad);                           
            jac[0][2] = -v * cos(gamma_rad) * deg_to_rad;           
            jac[1][0] = D / (m * H); 
            jac[1][1] = -(2.0 * D) / (m * v);
            jac[1][2] = g * cos(gamma_rad) * deg_to_rad;
            jac[2][0] = - (L * rad_to_deg) / (m * v * H);
            jac[2][1] = rad_to_deg * ( (L / (m * v * v)) - (g / (v * v)) * cos(gamma_rad) );
            jac[2][2] = -(g / v) * sin(gamma_rad);
};