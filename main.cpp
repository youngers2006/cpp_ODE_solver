#include "Solver.h"
int main() {
    std::string input_filename = "parameters.txt"; 
    std::string output_filename = "output_file.txt"; 

    try {
        // 
        Solver ODE_solver;
        ODE_solver.Run(
            input_filename, 
            output_filename
        );
    } catch (const std::exception& e) {
        // notify user of error.
        std::cerr << "Solver failed to solve system" << std::endl;
        std::cerr << "Reason: " << e.what() << std::endl;
        return 1;
    }
    return 0;
};