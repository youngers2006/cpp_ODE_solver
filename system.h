#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
class System {
    protected:
        std::vector<double> parameters;
        std::vector<double> state;
        double time;
    public:
        System() = delete; // disallow empty instances of system as they are not useful
        System(
            const std::vector<double>& params, 
            const std::vector<double>& ics,
            const double& itime
        );
        const std::vector<double>& get_params() const;
        const std::vector<double>& get_state() const;
        const double& get_time() const;
        void set_params(
            const std::vector<double>& params
        );
        void set_state(
            const std::vector<double>& current_state
        );
        void set_time(
            const double& current_time
        );
        virtual ~System() = default; // define virtual destructor
        virtual void f(
            std::vector<double> y, 
            double t, 
            std::vector<double> dydt
        ) = 0;
};
#endif