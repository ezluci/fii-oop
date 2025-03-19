#include "Sort.h"
#include <iostream>

int main()
{
   Sort a(10, -4, 4);
   
   a.Print();
   std::cout << a.GetElementFromIndex(0) << '\n';
   a.QuickSort();
   a.Print();
   std::cout << a.GetElementFromIndex(0) << '\n';
   std::cout << "count = " << a.GetElementsCount() << '\n';
   std::cout << "\n\n";
   
   Sort b {2, 5, 1, 2, 5, 7, 2, 6, 2, 6};
   b.Print();
   b.BubbleSort(false);
   b.Print();
   std::cout << "\n\n";
   
   int v[] = {5, 5, 15, 0, 10};
   Sort c(5, v);
   c.Print();
   c.QuickSort(false);
   c.Print();
   std::cout << "\n\n";

   Sort d(5, 2,-5,3,0,1);
   d.Print();
   d.InsertSort(true);
   d.Print();
   std::cout << "\n\n";

   Sort e("12,5,25,46,46,-36,5,63");
   e.InsertSort();
   e.Print();
}