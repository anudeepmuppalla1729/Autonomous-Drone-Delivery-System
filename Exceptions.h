#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

template <typename T>
class DroneException : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return T::message();
    }
};

struct ObstacleDetected {
    static const char* message() { return "Obstacle detected! Re-routing..."; }
};

struct LowBattery {
    static const char* message() { return "Low battery! Navigating to nearest recharge station..."; }
};

#endif // EXCEPTIONS_H
