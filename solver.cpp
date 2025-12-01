#include "Solver.h"
void Solver::Run(std::string input_filename, std::string output_filename) {
    ExtractedDataTable input_data;
    std::cout << "Loading Input Data ..." << std::endl;
    FileParser::extract_data(input_filename, input_data);
    std::unique_ptr<System>     system_ptr;
    std::unique_ptr<Integrator> integrator_ptr;
    std::cout << "Building System ..." << std::endl;
    switch (input_data.ODE) {
    case 0:
        system_ptr = std::make_unique<re_entry_ODE>(
            input_data.ODE_params,
            input_data.ODE_initial_conditions,
            0
        );
        break;
    case 1:
        system_ptr = std::make_unique<Satelite_dynamicsODE>(
            input_data.ODE_params,
            input_data.ODE_initial_conditions,
            0
        );
    default:
        throw std::runtime_error("System index out of defined bounds.");
        break;
    }
    std::cout << "Building Timescheme ..." << std::endl;
    switch (input_data.time_scheme) {
    case 0:
        integrator_ptr = std::make_unique<Euler_f>();
        break;
    case 1:
        integrator_ptr = std::make_unique<RK4>();
        break;
    case 2:
        integrator_ptr = std::make_unique<BackwardEuler>();
        break;
    default:
        throw std::runtime_error("Integration index out of defined bounds.");
        break;
    }
    
    double dt = input_data.dt;
    std::vector<double> state;
    std::vector<std::vector<double>> output_table;
    std::cout << "Running Solver ..." << std::endl;

    state = system_ptr->get_state();
    state.insert(state.begin(), system_ptr->get_time());
    output_table.push_back(state);

    for (double t = dt; t <= input_data.T; t += dt) {
        integrator_ptr->step(*system_ptr, dt);
        state = system_ptr->get_state();
        state.insert(state.begin(), t);
        output_table.push_back(state);
    }

    std::cout << "Solver Finished." << std::endl;
    std::cout << "Saving Results ..." << std::endl;
    FileParser::output_to_file(output_filename, output_table);
    std::cout << "Save successful." << std::endl;
    std::cout << "Process complete." << std::endl;
};

void Solver::create_input_file(std::string& filename, ExtractedDataTable& data) {
    FileParser::create_input_file(filename, data);
};