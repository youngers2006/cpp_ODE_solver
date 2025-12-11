#include "Solver.h"
void solver() {
    std::vector<std::string> inputs_files = {};
    std::vector<std::string> output_files = {};
    Solver ODE_solver;
    std::string input_filename;
    std::string output_filename;
    for (int i = 0; i < inputs_files.size(); ++i) {
        input_filename = inputs_files[i];
        output_filename = output_files[i];
        ODE_solver.Run(
            input_filename, 
            output_filename
        );
    };
};