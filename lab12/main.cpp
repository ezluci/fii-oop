#include "CatalogRO.h"
#include "Student.h"
#include "Engleza.h"
#include "Romana.h"
#include "Informatica.h"
#include "Matematica.h"
#include "Optional1.h"
#include "Optional2.h"
#include <iostream>

int main() {
   CatalogRO catalog;

   Student st1;
   st1.nume = "student 1";
   st1.adaugaMaterie(new Engleza(), 5);
   st1.adaugaMaterie(new Romana(), 7.5);
   st1.adaugaMaterie(new Optional1(), 4);
   catalog.adaugaStudent(&st1);

   Student st2;
   st2.nume = "student 2";
   st2.adaugaMaterie(new Matematica(), 7.2);
   st2.adaugaMaterie(new Romana(), 8);
   st2.adaugaMaterie(new Optional2(), 9);
   catalog.adaugaStudent(&st2);

   Student st3;
   st3.nume = "student 3";
   st3.adaugaMaterie(new Matematica(), 9);
   st3.adaugaMaterie(new Informatica(), 10);
   st3.adaugaMaterie(new Optional1(), 10);
   catalog.adaugaStudent(&st3);

   std::cout << "catalogul este pt programul " << catalog.getProgram() << '\n';

   std::vector<Student*> catalog_ranking = catalog.obtineRanking();
   for (const Student* student : catalog_ranking) {
      std::cout << student->nume << ": " << student->mediaGenerala() << '\n';
   }

   std::vector<Student*> catalog_filtrat = catalog.obtineStudenti([](const Student* student) {
      return student->mediaGenerala() >= 7;
   });

   std::cout << "catalog filtrat size: " << catalog_filtrat.size() << '\n';
}