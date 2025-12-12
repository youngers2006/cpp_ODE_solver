#include "Solver.h"
int main() {
    std::string input_filename = "parameters.txt"; 
    std::string output_filename = "output.txt"; 

    try {
        // attempt to run solver
        Solver ODE_solver;
        ODE_solver.Run(
            input_filename, 
            output_filename
        );
    } catch (const std::exception& e) {
        // catch any errors produced by the solver, notify user of error.
        std::cerr << "Solver failed to solve system" << std::endl;
        std::cerr << "Reason: " << e.what() << std::endl;
        return 1;
    }
    return 0;
};