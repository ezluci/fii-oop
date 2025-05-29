#pragma once
#include "Materie.h"

class Optional1 : public Materie {
   std::string getNume() const override;
   std::string getTip() const override;
   int getCredite() const override;
};