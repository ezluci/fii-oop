#pragma once
#include "Materie.h"
#include <vector>

class Student {
public:
   std::vector<std::pair<Materie*, float>> materii;
   std::string nume;
   std::string matricol;

   Student();
   void adaugaMaterie(Materie* materie, float nota);
   std::vector<float> obtineNote() const;
   float mediaGenerala() const;
};