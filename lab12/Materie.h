#pragma once
#include <string>

class Materie {
public:
   Materie();
   virtual std::string getNume() const = 0;
   virtual std::string getTip() const = 0;
   virtual int getCredite() const = 0;
};