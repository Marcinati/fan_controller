#include "Fan.hpp"
#include <stdexcept>
#include <cmath>

void Fan::checkSpeed(int newRpm) const {
    if ((newRpm < 1000 and newRpm != 0) or newRpm > 3000) {
        throw std::invalid_argument("Invalid speed");
    }
}

void Fan::setSpeed(int newRpm) {
    checkSpeed(newRpm);
    rpm = newRpm;
}

int Fan::getSpeed() const {
    return rpm;
}
