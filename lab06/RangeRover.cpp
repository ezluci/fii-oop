#include "RangeRover.h"
#include "Weather.h"

RangeRover::RangeRover()
{
   this->name = "Range Rover";
   this->fuelCapacity = 60;
   this->fuelConsumption = 6.5;
   this->avgSpeed[Weather::Rain] = 120;
   this->avgSpeed[Weather::Sunny] = 170;
   this->avgSpeed[Weather::Snow] = 70;
}

float RangeRover::GetRaceTime(float circuitLength, Weather weather)
{
   if (fuelCapacity / fuelConsumption * 100 < circuitLength)
      return -1;
   return circuitLength / avgSpeed[weather] + 3;
}