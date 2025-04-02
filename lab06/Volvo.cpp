#include "Volvo.h"
#include "Weather.h"

Volvo::Volvo()
{
   this->name = "Volvo";
   this->fuelCapacity = 50;
   this->fuelConsumption = 6;
   this->avgSpeed[Weather::Rain] = 90;
   this->avgSpeed[Weather::Sunny] = 120;
   this->avgSpeed[Weather::Snow] = 50;
}

float Volvo::GetRaceTime(float circuitLength, Weather weather)
{
   if (fuelCapacity / fuelConsumption * 100 < circuitLength)
      return -1;
   return circuitLength / avgSpeed[weather] + 3;
}