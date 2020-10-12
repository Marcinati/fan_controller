#pragma once
#include "../IThermometer.hpp"

class StubThermometer : public IThermometer {
public:
    double getTemperature() const override {
        return -1.0;
    }
};