#ifndef SOLVER_H
#define SOLVER_H
#include "integrator.h"
#include "RK4.h"
#include "Euler_f.h"
#include "BackwardEuler.h"
#include "system.h"
#include "re_entryODE.h"
#include "satelite_attitude_dynamicsODE.h"
#include "FileParser.h"
#include <memory>
#include <iostream>

// Solver class
// Class methods: default constructor, default destructor, run solver function, input file creation function
class Solver {
    public:
        // Solver constructor - default
        Solver()  = default;

        // Solver destructor - default
        ~Solver() = default;

        // Run solver function 
        // args: name of file storing system details, name of file to output results to
        // output: creates output txt file containing solver results
        void Run(
            std::string input_filename, 
            std::string output_filename
        );

        // Creates a txt file with given system data 
        // args: name of file to store system details, data to place in file
        // output: creates output txt file containing system data
        void create_input_file(
            std::string& filename, 
            ExtractedDataTable& data 
        );
};
#endif