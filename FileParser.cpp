#include "FileParser.h"

void FileParser::extract_data(std::string& filename, ExtractedDataTable& data_table) {
    // Initialise the input filestream.
    std::ifstream rfile;

    // Try to open the file and check if file can be opened, if not, throw an error.
    rfile.open(filename);
    if (!rfile.is_open()) {
        throw std::invalid_argument("File could not be opened, please check filename.");
    }

    // read the first 3 lines of the file which should contain all required data.
    std::string line1, line2, line3;
    std::getline(rfile, line1);
    std::getline(rfile, line2);
    std::getline(rfile, line3);

    // strip the first line down to obtain all solver settings by converting it to a string stream.
    std::stringstream sstream;
    sstream << line1;
    sstream >> data_table.ODE;
    sstream >> data_table.time_scheme;
    sstream >> data_table.T;
    sstream >> data_table.dt;

    // clear the last data from the string stream.
    sstream.clear();
    sstream.str("");

    // strip line two down to obtain all parameters in the file with a string stream.
    sstream << line2;
    double val;
    std::vector<double> param_vec;
    while (sstream >> val) {
        param_vec.push_back(val);
    }
    data_table.ODE_params = param_vec;

    // clear the last data from the string stream.
    sstream.clear();
    sstream.str("");

    // strip line three down to obtain the initial conditions in the file.
    sstream << line3;
    std::vector<double> init_vec;
    while (sstream >> val) {
        init_vec.push_back(val);
    }
    data_table.ODE_initial_conditions = init_vec;
};

void FileParser::output_to_file(std::string& filename, std::vector<std::vector<double>>& data) {
    // Initialise the output filestream.
    std::ofstream data_file(filename);

    // Try to open the file and check if file can be opened, if not, throw an error.
    if (!data_file.is_open()) {
        throw std::invalid_argument("Could not create the file under the requested filename, please retry.");
    }

    // create first element mask.
    bool first_element;

    // loop through all rows of the output matrix.
    for (const std::vector<double>& row : data) {

        // at the start of each row set the mask to true.
        first_element = true;

        // loop through all elements of the row.
        for (const double& element : row) {

            // when not the first element blank space must be added to spearte from the previous entry.
            if (!first_element) {
                data_file << " ";
            }

            // add the current entry.
            data_file << element;
            first_element = false;
        }

        // add a newline at the end of the current row.
        data_file << "\n";
    }
    data_file.close();
};

void FileParser::create_input_file(std::string& filename, ExtractedDataTable& data) {
    // Initialise the output file stream.
    std::ofstream data_file(filename);

    // if the file cannot be opened hrow an error.
    if (!data_file.is_open()) {
        throw std::invalid_argument("Couldnt create input file, please try a different filename.");
    }

    // for each element of the datatable input it to the file followed by a blankspace.
    data_file << data.ODE;
    data_file << " ";
    data_file << data.time_scheme;
    data_file << " ";
    data_file << data.T;
    data_file << " ";
    data_file << data.dt;
    data_file << "\n";

    // for each parameter in the table, add it to the file.
    for (const auto& element : data.ODE_params) {
        data_file << element;
        data_file << " ";
    }
    data_file << "\n";

    // for each initial condition in the table, add it to the file.
    for (const auto& element : data.ODE_initial_conditions) {
        data_file << element;
        data_file << " ";
    }
    data_file.close();
};