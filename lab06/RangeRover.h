#pragma once
#include "Car.h"

class RangeRover : public Car {
public:
   RangeRover();
   float GetRaceTime(float circuitLength, Weather weather);
};