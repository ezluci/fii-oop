#include "Car.h"

std::string Car::GetName() const
{
   return this->name;
}

void Car::SetName(const std::string &name)
{
   this->name = name;
}