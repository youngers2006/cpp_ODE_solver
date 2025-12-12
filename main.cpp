#include "Solver.h"
int main() {
    std::cout << "Does an input file exist (y/n)" << std::endl; 

    char response;
    std::cin >> response;
    bool file_exists = (response == 'y' || response == 'Y');

    std::string input_filename = "input_file.txt"; 
    std::string output_filename = "IE_sat_1.txt"; 
    Solver ODE_solver;

    if (!file_exists) {
        ExtractedDataTable data;
        data.ODE = 0;
        data.time_scheme = 1.0;
        data.T = 1000.0;
        data.dt = 0.1;
        data.ODE_params = {
            0.15, 
            0.1, 
            0.855, 
            100.0, 
            9.81, 
            5.0
        }; // [rho0, Cl, Cd, m, g, A]
        data.ODE_initial_conditions = {
            50000.0, 
            100.0, 
            30.0
        }; // [h, v, gamma]
        ODE_solver.create_input_file(
            input_filename, 
            data
        );
    }
    
    ODE_solver.Run(
        input_filename, 
        output_filename
    );
    return 0;
};