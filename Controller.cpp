#include "Controller.hpp"

Controller::Controller(IThermometer& t,
                       Fan,
                       double,
                       double,
                       std::shared_ptr<LcdDisplay>)
    : thermometer_(t) {}

void Controller::updateRpm() {}

void Controller::displayInfo() {}
