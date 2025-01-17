#ifndef PATH_OPTIMIZER_INCLUDE_PATH_OPTIMIZER_DATA_STRUCT_VEHICLE_STATE_FRENET_HPP_
#define PATH_OPTIMIZER_INCLUDE_PATH_OPTIMIZER_DATA_STRUCT_VEHICLE_STATE_FRENET_HPP_
#include <vector>

class State;

class VehicleState {
 public:
    VehicleState();
    VehicleState(const State &start_state,
                 const State &end_state,
                 double offset = 0.0,
                 double heading_error = 0.0);
    ~VehicleState();
    const State &getStartState() const;
    const State &getTargetState() const;
    void setStartState(const State &state);
    void setTargetState(const State &state);
    std::vector<double> getInitError() const;
    void setInitError(double init_offset, double init_heading_error);

 private:
    // Initial state.
    State *start_state_;
    // Target state.
    State *target_state_;
    // Initial error with reference line.
    double initial_offset_{};
    double initial_heading_error_{};
};
#endif //PATH_OPTIMIZER_INCLUDE_PATH_OPTIMIZER_DATA_STRUCT_VEHICLE_STATE_FRENET_HPP_
