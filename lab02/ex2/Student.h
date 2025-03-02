#pragma once
#include <string>

class Student
{
private:
   std::string name;
   float gradeMath;
   float gradeEnglish;
   float gradeHistory;

public:
   Student();

   std::string getName() const;
   void setName(std::string newName);

   float getGradeMath() const;
   void setGradeMath(float newGrade);

   float getGradeEnglish() const;
   void setGradeEnglish(float newGrade);

   float getGradeHistory() const;
   void setGradeHistory(float newGrade);

   // returns the average of the 3 grades
   float averageGrade() const;
};