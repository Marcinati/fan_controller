#include "external/catch.hpp"
#include "external/hippomocks.h"
#include "Controller.hpp"
#include "SlowThermometer/SlowThermometer.hpp"

SCENARIO("Controller can control Fan") {
    GIVEN("Controller, Thermometer, Fan, target temperature = 36.6C, tolerance = 0.5C") {
        SlowThermometer thermometer;
        Fan fan;
        double targetTemperature = 36.6;
        double tolerance = .5;
        Controller oldController{thermometer, fan, targetTemperature, tolerance, nullptr};

        WHEN("Temperature drops below 0") {
            thermometer.setTemperature(-1);
            auto temperature = thermometer.getTemperature();
            REQUIRE(temperature < 0);

            THEN("Fan should be disabled") {
                REQUIRE(fan.getSpeed() == 0);
            }
        }
    }
}