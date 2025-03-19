#pragma once
#include <initializer_list>
#include <random>

class Sort
{
   int count;
   int *values;

   void _QuickSort(int st, int dr, bool ascendent, std::random_device &);
public:
   Sort(int count, int min_val, int max_val);
   Sort(std::initializer_list<int> list);
   Sort(int count, int values[]);
   Sort(int count, ...); // Sort(3, 5,2,7)
   Sort(char string[]); // "10,40,100,5,70"
   ~Sort();

   void InsertSort(bool ascendent = true);
   void QuickSort(bool ascendent = true);
   void BubbleSort(bool ascendent = true);
   void Print();
   int  GetElementsCount();
   int  GetElementFromIndex(int index);
};
