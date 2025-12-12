#include "Solver.h"
void Solver::Run(std::string input_filename, std::string output_filename) {
    // create output data struct.
    ExtractedDataTable input_data;

    // notify user of loading.
    std::cout << "Loading Input Data ..." << std::endl;

    // use helper class to extract data from input file.
    try {
        FileParser::extract_data(input_filename, input_data);
    } catch (const std::exception& e) {
        // notify user of error and log results up to this point.
        std::cerr << "Failed to open input file" << std::endl;
        std::cerr << "Reason: " << e.what() << std::endl;
        throw;
    }

    // initialise unique pointers for intergrator and system classes, choice has not occured yet so initialise as abstact class.
    std::unique_ptr<System>     system_ptr;
    std::unique_ptr<Integrator> integrator_ptr;

    // Notify user that system is being built.
    std::cout << "Building System ..." << std::endl;
    
    // switch case for the system choice.
    // depending on what value is in the file, point the system pointer to a child class created in each case.
    // if the index is out of bounds throw an error.
    switch (input_data.ODE) {
    case 0:
        system_ptr = std::make_unique<re_entry_ODE>(
            input_data.ODE_params,
            input_data.ODE_initial_conditions,
            0
        );
        break;
    case 1:
        system_ptr = std::make_unique<Satellite_dynamicsODE>(
            input_data.ODE_params,
            input_data.ODE_initial_conditions,
            0
        );
        break;
    default:
        throw std::runtime_error("System index out of defined bounds.");
        break;
    }

    // notify the user the timescheme is being set up
    std::cout << "Building Timescheme ..." << std::endl;

    // switch case for the time scheme choice.
    // depending on what value is in the file, point the integrator pointer to a child class created in each case.
    // if the index is out of bounds throw an error.
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
        throw std::runtime_error("Integrator index out of defined bounds.");
        break;
    }
    
    // initialise timestep, state and output table.
    double dt = input_data.dt;
    std::vector<double> state;
    std::vector<std::vector<double>> output_table;

    // ntify user the solver is running.
    std::cout << "Running Solver ..." << std::endl;

    // from the system obtain the current state and insert it into the state vector.
    state = system_ptr->get_state();
    state.insert(state.begin(), system_ptr->get_time());
    output_table.push_back(state);

    // find the number of iterations to loop through.
    int num_steps = std::round(input_data.T / input_data.dt);

    // initialise the time as zero.
    double t = 0;

    // try and run solver, if an error occurs, report the time to the user and save current data.
    try {
        for (int step = 1; step <= num_steps; ++step) {
            // get current time from the iteration.
            t = step * input_data.dt;

            // step with the integrator through one timestep in the system.
            integrator_ptr->step(*system_ptr, dt);

            // log state data to output matrix.
            state = system_ptr->get_state();
            state.insert(state.begin(), t);
            output_table.push_back(state);
        }
    } catch (const std::exception& e) {
        // notify user of error and log results up to this point.
        std::cerr << "Solver failed at t = " << t << "seconds" << std::endl;
        std::cerr << "Reason: " << e.what() << std::endl;
        std::cerr << "Saving partial results to: " << output_filename << std::endl;
        try {
            FileParser::output_to_file(output_filename, output_table);
        } catch (const std::exception& save_error) {
            std::cerr << "Warning: Could not save partial results." << std::endl;
            std::cerr << "Save Error: " << save_error.what() << std::endl;
        }
        throw;
    }

    // If the solver is successful, notify the user and save data.
    std::cout << "Solver Finished." << std::endl;
    std::cout << "Saving Results ..." << std::endl;
    try {
        FileParser::output_to_file(output_filename, output_table);
    } catch (const std::exception& e) {
        std::cerr << "Save failed" << std::endl;
        std::cerr << "Reason: " << e.what() << std::endl;
    }
    std::cout << "Save successful." << std::endl;
    std::cout << "Process complete." << std::endl;
};

// function to allow user to create an input file using the solver class.
void Solver::create_input_file(std::string& filename, ExtractedDataTable& data) {
    // calls helper function.
    FileParser::create_input_file(filename, data);
};