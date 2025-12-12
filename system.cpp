#include <vector>
#include "system.h"
System::System(const std::vector<double>& params, 
               const std::vector<double>& ics,
               const double& itime) 
        : parameters(params), state(ics), time(itime) {};

const std::vector<double>& System::get_params() const {
    // return all system parameters.
    return parameters;
};

const std::vector<double>& System::get_state() const {
    // return the system state.
    return state;
};

const double& System::get_time() const {
    // return system time.
    return time;
};

void System::set_params(const std::vector<double>& params) {
    // set system parameters.
    parameters = params;
};

void System::set_state(const std::vector<double>& current_state) {
    // set system state.
    state = current_state;
};

void System::set_time(const double& current_time) {
    // set system time.
    time = current_time;
};