#pragma once

class Fan {
    int rpm = 0;

public:
    void checkSpeed(int newRpm) const;
    void setSpeed(int newRpm);
    int getSpeed() const;
};
