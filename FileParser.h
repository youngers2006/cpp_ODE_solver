#ifndef FILEPARSER_H
#define FILEPARSER_H
#include <vector>
#include <sstream>
#include <string>
#include <istream>
#include <fstream>
#include <stdexcept>
#include <iomanip>

// Struct to store data imported from input file
// Members: ODE idx, time scheme idx, T, dt, parameters, initial conditions
struct ExtractedDataTable {
    int ODE; // index of selected ODE
    int time_scheme; // index of selected time scheme
    double T; // time to integrate up to
    double dt; // step size
    std::vector<double> ODE_params; // System parameters
    std::vector<double> ODE_initial_conditions; // Initial conditions of the ODE system
};

// utility class of static methods to allow the solver to read and write to files
// Class methods: extraction function (static), output file function (static), create file function (static)
class FileParser {
    public:
        // static method to extract data from the formatted file and return a struct as defined above
        static void extract_data(
            std::string& filename, 
            ExtractedDataTable& data_table
        );

        // static method to write solution table found by solver to a file
        // args: filename, data
        // return: void
        static void output_to_file(
            std::string& filename, 
            std::vector<std::vector<double>>& data
        ); 

        // static method 
        // args: filename, data
        // return: void
        static void create_input_file(
            std::string& filename, 
            ExtractedDataTable& data
        );
};
#endif