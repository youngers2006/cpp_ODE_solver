#include "Solver.h"

int main() {
    std::string input_filename;
    std::string output_filename;
    ExtractedDataTable data;
    data.ODE = 0;
    data.time_scheme = 0;
    data.T = 10;
    data.dt = 0.1;
    data.ODE_params = {0.0, 0.0, 0.0, 0.0, 0.0};
    data.ODE_initial_conditions = {0.0, 0.0, 0.0};
    Solver ODE_solver;
    ODE_solver.create_input_file(input_filename, data);
    ODE_solver.Run(input_filename, output_filename);
    return 0;
};