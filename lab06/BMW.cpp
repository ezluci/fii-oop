#include "BMW.h"
#include "Weather.h"

BMW::BMW()
{
   this->name = "BMW";
   this->fuelCapacity = 70;
   this->fuelConsumption = 9;
   this->avgSpeed[Weather::Rain] = 100;
   this->avgSpeed[Weather::Sunny] = 170;
   this->avgSpeed[Weather::Snow] = 70;
}

float BMW::GetRaceTime(float circuitLength, Weather weather)
{
   if (fuelCapacity / fuelConsumption * 100 < circuitLength)
      return -1;
   return circuitLength / avgSpeed[weather];
}