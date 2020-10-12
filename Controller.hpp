#pragma once
#include "Fan.hpp"
#include "IThermometer.hpp"
#include <memory>

class LcdDisplay;

class Controller {
    IThermometer& thermometer_;
    Fan& fan_;
public:
    Controller(IThermometer& t, Fan& f, double, double, std::shared_ptr<LcdDisplay>);
    void updateRpm();
    void displayInfo();
};
