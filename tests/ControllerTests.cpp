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
        Controller oldController{thermometer, fan, targetTemperature, tolerance, nullptr};

        WHEN("Temperature drops below 0") {
            //thermometer.setTemperature(-1);
            auto temperature = thermometer.getTemperature();
            REQUIRE(temperature < 0);

            THEN("Fan should be disabled") {
                REQUIRE(fan.getSpeed() == 0);
            }
        }

        WHEN("Temperature rise above 100") {
            //thermometer.setTemperature(-1);
            auto temperature = thermometer.getTemperature();
            REQUIRE(temperature > 0);

            THEN("Fan should work at max speed") {
                constexpr int maxSpeed = 3000;
                REQUIRE(fan.getSpeed() == maxSpeed);
            }
        }
    }
}