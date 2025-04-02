#include <algorithm>
#include <iostream>
#include "Circuit.h"
#include "Car.h"
#include "Weather.h"

Circuit::Circuit()
{
   this->length = 0;
   this->weather = Weather::Sunny;
}

void Circuit::SetLength(int length)
{
   this->length = length;
}

void Circuit::SetWeather(Weather weather)
{
   this->weather = weather;
}

void Circuit::AddCar(Car* car)
{
   this->cars.push_back(car);
}

void Circuit::Race()
{
   this->ranking.clear();
   for (Car* car : this->cars)
   {
      float time = car->GetRaceTime(this->length, this->weather);
      this->ranking.push_back(std::make_pair(time, car));
   }
   
   std::sort(
      this->ranking.begin(),
      this->ranking.end(),
      [](std::pair<float, Car*> &A, std::pair<float, Car*> &B) {
         if (A.first == B.first) return false;
         if (A.first == -1)   return false;
         if (B.first == -1)   return true;
         return A.first < B.first;
      }
   );
}

void Circuit::ShowFinalRanks()
{
   for (auto &[time, car] : this->ranking)
   {
      if (time == -1)   return;
      std::cout << car->GetName() << " finished in " << time << " seconds!\n";
   }
}

void Circuit::ShowWhoDidNotFinish()
{
   for (auto &[time, car] : this->ranking)
   {
      if (time != -1)   continue;
      std::cout << car->GetName() << " did not finish the race!\n";
   }
}
