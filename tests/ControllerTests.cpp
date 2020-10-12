#include "external/catch.hpp"
#include "external/hippomocks.h"
#include "Controller.hpp"
#include "tests/StubThermometer.hpp"


SCENARIO("Controller can control Fan") {
    GIVEN("Controller, Thermometer, Fan, target temperature = 36.6C, tolerance = 0.5C") {
        StubThermometer thermometer;
        Fan fan;
        double targetTemperature = 36.6;
        double tolerance = .5;
        Controller cut{thermometer, fan, targetTemperature, tolerance, nullptr};

        WHEN("Temperature drops below 0, when updateRpm is called") {
            thermometer.temperature = -1.0;
            cut.updateRpm();

            THEN("Fan should be disabled") {
                REQUIRE(fan.getSpeed() == disableSpeed);
            }
        }

        WHEN("Temperature rise above 100, when updateRpm is called") {
            thermometer.temperature = 101.0;
            cut.updateRpm();
        
            THEN("Fan should work at max speed") {
                REQUIRE(fan.getSpeed() == maxSpeed);
            }
        }
    }
}