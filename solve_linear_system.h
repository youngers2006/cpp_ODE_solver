#ifndef SOLVE_LINEAR_SYSTEM_H
#define SOLVE_LINEAR_SYSTEM_H
#include <cmath>
#include <vector>
#include <iostream>

std::vector<double> solve_linear_system(
    std::vector<std::vector<double>> A, 
    std::vector<double> b
);
#endif