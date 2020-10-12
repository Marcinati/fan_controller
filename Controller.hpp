#pragma once
#include "Fan.hpp"
#include "IThermometer.hpp"
#include <memory>

class LcdDisplay;

class Controller {
    IThermometer& thermometer_;
public:
    Controller(IThermometer& t, Fan, double, double, std::shared_ptr<LcdDisplay>);
    void updateRpm();
    void displayInfo();
};
