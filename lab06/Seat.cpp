#include "Seat.h"
#include "Weather.h"

Seat::Seat()
{
   this->name = "Seat";
   this->fuelCapacity = 40;
   this->fuelConsumption = 4.7;
   this->avgSpeed[Weather::Rain] = 80;
   this->avgSpeed[Weather::Sunny] = 100;
   this->avgSpeed[Weather::Snow] = 50;
}

float Seat::GetRaceTime(float circuitLength, Weather weather)
{
   if (fuelCapacity / fuelConsumption * 100 < circuitLength)
      return -1;
   return circuitLength / avgSpeed[weather] + 5;
}