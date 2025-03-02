#include "CompareStudents.h"

int compareStudentsByName(Student &A, Student &B)
{
   int val = A.getName().compare(B.getName());
   if (val < 0)   val = -1;
   if (val > 0)   val = +1;
   return val;
}

int compareStudentsByGradeMath(Student &A, Student &B)
{
   if (A.getGradeMath() < B.getGradeMath())
      return -1;
   if (A.getGradeMath() > B.getGradeMath())
      return +1;
   return 0;
}

int compareStudentsByGradeEnglish(Student &A, Student &B)
{
   if (A.getGradeEnglish() < B.getGradeEnglish())
      return -1;
   if (A.getGradeEnglish() > B.getGradeEnglish())
      return +1;
   return 0;
}

int compareStudentsByGradeHistory(Student &A, Student &B)
{
   if (A.getGradeHistory() < B.getGradeHistory())
      return -1;
   if (A.getGradeHistory() > B.getGradeHistory())
      return +1;
   return 0;
}

int compareStudentsByAverageGrade(Student &A, Student &B)
{
   if (A.averageGrade() < B.averageGrade())
      return -1;
   if (A.averageGrade() > B.averageGrade())
      return +1;
   return 0;
}