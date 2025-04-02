#pragma once
#include "Car.h"

class Seat : public Car {
public:
   Seat();
   float GetRaceTime(float circuitLength, Weather weather);
};