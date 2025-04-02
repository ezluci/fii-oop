#pragma once
#include "Car.h"

class Fiat : public Car {
public:
   Fiat();
   float GetRaceTime(float circuitLength, Weather weather);
};