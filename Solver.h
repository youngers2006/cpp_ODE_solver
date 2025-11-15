#ifndef SOLVER_H
#define SOLVER_H
#include "integrator.h"
#include "RK4.h"
#include "Euler_f.h"
#include "system.h"
#include "re_entryODE.h"
#include "satelite_attitude_dynamicsODE.h"
#include "FileParser.h"
#include <memory>
#include <iostream>
class Solver {
    public:
        Solver() = default;
        ~Solver() = default;
        void Run(std::string input_filename, std::string output_filename);
};
#endif