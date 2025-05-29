#pragma once
#include "Student.h"
#include <vector>
#include <functional>

class Catalog {
public:
   std::vector<Student*> studenti;
   
   Catalog();
   void adaugaStudent(Student* student);
   std::vector<Student*> obtineRanking() const;
   std::vector<Student*> obtineStudenti(std::function<bool(const Student*)> regula) const;
   virtual std::string getProgram() const = 0;
};