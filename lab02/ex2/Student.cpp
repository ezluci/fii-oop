#include "Student.h"
#include <string>

Student::Student()
   : name(""), gradeMath(0), gradeEnglish(0), gradeHistory(0)
{

}


std::string Student::getName() const
{
   return this->name;
}

void Student::setName(std::string newName)
{
   this->name = newName;
}


float Student::getGradeMath() const
{
   return this->gradeMath;
}

void Student::setGradeMath(float newGrade)
{
   this->gradeMath = newGrade;
}


float Student::getGradeEnglish() const
{
   return this->gradeEnglish;
}

void Student::setGradeEnglish(float newGrade)
{
   this->gradeEnglish = newGrade;
}


float Student::getGradeHistory() const
{
   return this->gradeHistory;
}

void Student::setGradeHistory(float newGrade)
{
   this->gradeHistory = newGrade;
}


float Student::averageGrade() const
{
   return (this->gradeMath + this->gradeEnglish + this->gradeHistory) / 3;
}