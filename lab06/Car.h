#pragma once
#include <string>
#include "Weather.h"

class Car {
protected:
   std::string name;
   float fuelCapacity;
   float fuelConsumption;
   float avgSpeed[WEATHER_COUNT];

public:
   virtual float GetRaceTime(float circuitLength, Weather weather) = 0;
   
   std::string GetName() const;
   void SetName(const std::string&);
};