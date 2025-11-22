#include "Solver.h"

int main() {
    std::string input_filename = "input_file.txt";
    std::string output_filename = "output_file.txt";
    ExtractedDataTable data;
    data.ODE = 0;
    data.time_scheme = 1;
    data.T = 1000.0;
    data.dt = 0.1;
    data.ODE_params = {0.15, 0.1, 0.855, 10000.0, 9.81, 5.0}; // [rho0, Cl, Cd, m, g, A]
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