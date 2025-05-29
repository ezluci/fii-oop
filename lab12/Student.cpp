#include "Student.h"

Student::Student() {

}

void Student::adaugaMaterie(Materie* materie, float nota = 0) {
   this->materii.push_back(std::make_pair(materie, nota));
}

std::vector<float> Student::obtineNote() const {
   std::vector<float> note;
   for (auto &[materie, nota] : this->materii) {
      note.push_back(nota);
   }
   return note;
}

float Student::mediaGenerala() const {
   
   float suma_note = 0;
   int suma_credite = 0;
   for (std::pair<Materie*, float> materie : this->materii) {
      suma_note += materie.second * materie.first->getCredite();
      suma_credite += materie.first->getCredite();
   }

   return suma_note / suma_credite;
}