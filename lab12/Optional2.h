#pragma once
#include "Materie.h"

class Optional2 : public Materie {
   std::string getNume() const override;
   std::string getTip() const override;
   int getCredite() const override;
};