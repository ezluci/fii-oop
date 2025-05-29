#include "Catalog.h"
#include <algorithm>

Catalog::Catalog() {

}

void Catalog::adaugaStudent(Student* student) {
   this->studenti.push_back(student);
}

std::vector<Student*> Catalog::obtineRanking() const {
   std::vector<Student*> studenti_rank = this->studenti;
   std::sort(studenti_rank.begin(), studenti_rank.end(), [](const Student* A, const Student* B) {
      return A->mediaGenerala() > B->mediaGenerala();
   });
   return studenti_rank;
}

std::vector<Student*> Catalog::obtineStudenti(std::function<bool(const Student*)> regula) const {
   std::vector<Student*> studenti_filtrat;
   for (Student* student : this->studenti) {
      if (regula(student)) {
         studenti_filtrat.push_back(student);
      }
   }
   return studenti_filtrat;
}