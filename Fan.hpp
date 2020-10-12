#pragma once

constexpr int maxSpeed = 3000;
constexpr int disableSpeed = 0;

class Fan {
    int rpm = 0;

public:
    void checkSpeed(int newRpm) const;
    void setSpeed(int newRpm);
    int getSpeed() const;
};
