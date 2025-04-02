#pragma once
#include "Weather.h"
#include "Car.h"
#include <vector>

class Circuit {
private:
   float length;
   Weather weather;
   std::vector<Car*> cars;
   std::vector<std::pair<float, Car*>> ranking;

public:
   Circuit();
   
   void SetLength(int length);
   
   void SetWeather(Weather weather);
   
   void AddCar(Car* car);
   
   void Race();
   
   // it will print the time each car needed to finish the
   // circuit sorted from the fastest car to the slowest.
   void ShowFinalRanks();

   // it is possible that some cars don't have
   // enough fuel to finish the circuit.
   void ShowWhoDidNotFinish();
};