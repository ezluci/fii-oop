#include "Student.h"
#include "CompareStudents.h"
#include <iostream>

int main(int argc, char *argv[])
{
   Student A, B;
   
   A.setName("alex");
   B.setName("liviu");
   
   A.setGradeMath(5);
   B.setGradeMath(8);

   A.setGradeEnglish(6);
   B.setGradeEnglish(6);

   A.setGradeHistory(2);
   B.setGradeHistory(9);

   std::cout << A.getName() << "'s grades:\n";
   std::cout << " - math:\t" << A.getGradeMath() << '\n';
   std::cout << " - english:\t" << A.getGradeEnglish() << '\n';
   std::cout << " - history:\t" << A.getGradeHistory() << '\n';
   std::cout << " - average:\t" << A.averageGrade() << '\n';
   std::cout << '\n';

   std::cout << B.getName() << "'s grades:\n";
   std::cout << " - math:\t" << B.getGradeMath() << '\n';
   std::cout << " - english:\t" << B.getGradeEnglish() << '\n';
   std::cout << " - history:\t" << B.getGradeHistory() << '\n';
   std::cout << " - average:\t" << B.averageGrade() << '\n';
   std::cout << '\n';


   int compare_name_val = compareStudentsByName(A, B);
   if (compare_name_val == -1)
      std::cout << A.getName() << "'s name is lexicographically smaller than " << B.getName() << "'s name.\n";
   else if (compare_name_val == +1)
      std::cout << A.getName() << "'s name is lexicographically larger than " << B.getName() << "'s name.\n";
   else
      std::cout << "Both students have the name " << A.getName() << "!\n";
   
   int compare_math_val = compareStudentsByGradeMath(A, B);
   if (compare_math_val == 0)
      std::cout << "The students have the same grade for mathematics!\n";
   else
      std::cout << (compare_math_val == -1 ? B.getName() : A.getName()) << " has the bigger grade for mathematics.\n";

   int compare_english_val = compareStudentsByGradeEnglish(A, B);
   if (compare_english_val == 0)
      std::cout << "The students have the same grade for english!\n";
   else
      std::cout << (compare_english_val == -1 ? B.getName() : A.getName()) << " has the bigger grade for english.\n";

   int compare_history_val = compareStudentsByGradeHistory(A, B);
   if (compare_history_val == 0)
      std::cout << "The students have the same grade for history!\n";
   else
      std::cout << (compare_history_val == -1 ? B.getName() : A.getName()) << " has the bigger grade for history.\n";

   std::cout << '\n';
   int compare_average_val = compareStudentsByAverageGrade(A, B);
   if (compare_average_val == -1)
      std::cout << "On average, " << B.getName() << " scored better than " << A.getName() << ".\n";
   else if (compare_average_val == +1)
      std::cout << "On average, " << A.getName() << " scored better than " << B.getName() << ".\n";
   else
      std::cout << "On average, both " << A.getName() << " and " << B.getName() << " had the same grades.\n";
}