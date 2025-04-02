#include <iostream>
#include "Circuit.h"
#include "Weather.h"
#include "Volvo.h"
#include "BMW.h"
#include "Seat.h"
#include "Fiat.h"
#include "RangeRover.h"

int main()
{
   Circuit c;
   c.SetLength(600);
   c.SetWeather(Weather::Rain);
   c.AddCar(new Volvo());
   c.AddCar(new BMW());
   c.AddCar(new Seat());
   c.AddCar(new Fiat());
   c.AddCar(new RangeRover());
   c.Race();
   c.ShowFinalRanks();
   c.ShowWhoDidNotFinish();
   std::cout << '\n';

   c.SetWeather(Weather::Sunny);
   c.SetLength(800);
   c.Race();
   c.ShowFinalRanks();
   c.ShowWhoDidNotFinish();
}
