#include "Fiat.h"
#include "Weather.h"

Fiat::Fiat()
{
   this->name = "Fiat";
   this->fuelCapacity = 30;
   this->fuelConsumption = 10;
   this->avgSpeed[Weather::Rain] = 90;
   this->avgSpeed[Weather::Sunny] = 110;
   this->avgSpeed[Weather::Snow] = 50;
}

float Fiat::GetRaceTime(float circuitLength, Weather weather)
{
   if (fuelCapacity / fuelConsumption * 100 < circuitLength)
      return -1;
   return circuitLength / avgSpeed[weather] + 1;
}