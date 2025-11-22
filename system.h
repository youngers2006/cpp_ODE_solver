#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
// Base class for all Systems.
// Class variables: parameters, state, time
// Class methods: custom constructor, setter functions, getter functions, default destructor (virtual), evaluation function (virtual)
class System {
    protected:
        std::vector<double> parameters; // System parameters
        std::vector<double> state; // Current Syatem state
        double time; // Current System time
    public:
        // disallow empty instances of system.
        System() = delete;

        // System constructor, user defined
        // args: parameters, initial conditions, initial time
        System(
            const std::vector<double>& params, 
            const std::vector<double>& ics,
            const double& itime
        );

        // System getter functions
        const std::vector<double>& get_params() const; // get system parameters
        const std::vector<double>& get_state() const; // get current state
        const double& get_time() const; // get current time

        // sets system parameters
        void set_params(
            const std::vector<double>& params 
        );

        // sets system state
        void set_state(
            const std::vector<double>& current_state
        );

        // sets system time
        void set_time(
            const double& current_time
        );

        // Default destructor for System.
        virtual ~System() = default; 

        // Evaluation function for System - modifies dydt in place
        // args: state vector, time, state derivative vector 
        // Returns: void
        virtual void f(
            const std::vector<double>& y, 
            double& t, 
            std::vector<double>& dydt
        ) = 0;
};
#endif