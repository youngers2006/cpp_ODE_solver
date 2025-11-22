#include "Solver.h"

int main() {
    std::string input_filename = "input_file.txt";
    std::string output_filename = "output_file.txt";
    ExtractedDataTable data;
    data.ODE = 0;
    data.time_scheme = 1;
    data.T = 10.0;
    data.dt = 0.1;
    data.ODE_params = {1.225, 0.0, 0.855, 100.0, 9.81}; // [rho0, Cl, Cd, m, g]
    data.ODE_initial_conditions = {50000.0, 100.0, 30.0}; // [h, v, gamma]
    Solver ODE_solver;
    ODE_solver.create_input_file(
        input_filename, 
        data
    );
    ODE_solver.Run(
        input_filename, 
        output_filename
    );
    return 0;
};