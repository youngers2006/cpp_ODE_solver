#include <vector>
#include "system.h"
System::System(const std::vector<double>& params, 
               const std::vector<double>& ics,
               const double& itime) 
        : parameters(params), state(ics), time(itime) {};

const std::vector<double>& System::get_params() const {
    return parameters;
};

const std::vector<double>& System::get_state() const {
    return state;
};

const double& System::get_time() const {
    return time;
};

void System::set_params(const std::vector<double>& params) {
    parameters = params;
};

void System::set_state(const std::vector<double>& current_state) {
    state = current_state;
};

void System::set_time(const double& current_time) {
    time = current_time;
};