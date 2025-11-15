#ifndef FILEPARSER_H
#define FILEPARSER_H
#include <vector>
#include <sstream>
#include <string>
#include <istream>

// define a struct to transport the imported data to the solver
struct ExtractedDataTable {
    int ODE; // index of ODE to select
    int time_scheme; // index of time scheme to select
    double T; // time to integrate up to
    double dt; // time intervals
    std::vector<double> ODE_params; // vector of params to define the ODE
    std::vector<double> ODE_initial_conditions; // vector of initial conditions to define the ODE
};

// define a datatable for exporting the data from the solver
using output_table = std::vector<std::vector<double>>;

// define a utility class of static methods to allow the solver to read and write to files
class FileParser {
    public: // methods must be public
        // static method to extract data from the formatted file and return a struct as defined above
        static void extract_data(std::string filename, ExtractedDataTable data_table);
        // static method to write solution table found by solver to a file
        static void output_to_file(std::string filename, output_table data); 
};
#endif