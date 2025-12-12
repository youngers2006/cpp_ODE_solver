#ifndef NEWTONRAPHSONSolver_H
#define NEWTONRAPHSONSolver_H
#include <cmath>
#include <iostream>
#include "system.h"
#include "vector_math_templates.h"
#include "solve_linear_system.h"
// Newton Raphson Solver for to find the roots of the next state equation when suing implicit euler.                        
std::vector<double> NewtonRaphsonSolver(
    System& ODE, 
    std::vector<double> y0, 
    double dt,
    double tolerance = 1e-9, 
    int max_iters = 50
);
#endif