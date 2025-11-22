#include "FileParser.h"

void FileParser::extract_data(std::string& filename, ExtractedDataTable& data_table) {
    std::ifstream rfile;
    rfile.open(filename);
    if (!rfile.is_open()) {
        throw std::invalid_argument("File could not be opened, please check filename.");
    }
    std::string line1, line2, line3;
    std::getline(rfile, line1);
    std::getline(rfile, line2);
    std::getline(rfile, line3);

    std::stringstream sstream;
    sstream << line1;
    sstream >> data_table.ODE;
    sstream >> data_table.time_scheme;
    sstream >> data_table.T;
    sstream >> data_table.dt;

    sstream.clear();
    sstream.str("");
    sstream << line2;
    double val;
    std::vector<double> param_vec;
    while (sstream >> val) {
        param_vec.push_back(val);
    }
    data_table.ODE_params = param_vec;

    sstream.clear();
    sstream.str("");
    sstream << line3;
    std::vector<double> init_vec;
    while (sstream >> val) {
        init_vec.push_back(val);
    }
    data_table.ODE_initial_conditions = init_vec;
};

void FileParser::output_to_file(std::string& filename, std::vector<std::vector<double>>& data) {
    std::ofstream data_file(filename);
    if (!data_file.is_open()) {
        throw std::invalid_argument("Could not create the file under the requested filename, please retry.");
    }
    bool first_element;
    for (const std::vector<double>& row : data) {
        first_element = true;
        for (const double& element : row) {
            if (!first_element) {
                data_file << " ";
            }
            data_file << element;
            first_element = false;
        }
        data_file << "\n";
    }
    data_file.close();
};

void FileParser::create_input_file(std::string& filename, ExtractedDataTable& data) {
    std::ofstream data_file(filename);
    if (!data_file.is_open()) {
        throw std::invalid_argument("Couldnt create input file, please try a different filename.");
    }
    data_file << data.ODE;
    data_file << " ";
    data_file << data.time_scheme;
    data_file << " ";
    data_file << data.T;
    data_file << " ";
    data_file << data.dt;
    data_file << "\n";
    for (const auto& element : data.ODE_params) {
        data_file << element;
        data_file << " ";
    }
    data_file << "\n";
    for (const auto& element : data.ODE_initial_conditions) {
        data_file << element;
        data_file << " ";
    }
    data_file.close();
};