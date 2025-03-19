#include "Sort.h"
#include <ctime>
#include <random>
#include <cstdarg>
#include <iostream>

Sort::Sort(int count, int min_val, int max_val)
{
   std::random_device rd;
   std::uniform_int_distribution dist(min_val, max_val);
   
   this->count = count;
   this->values = new int[count];
   for (int i = 0; i < count; ++i)
      this->values[i] = dist(rd);
}

Sort::Sort(std::initializer_list<int> list)
{
   this->count = list.size();
   this->values = new int[count];
   for (auto it = list.begin(); it != list.end(); ++it)
      this->values[it - list.begin()] = *it;
}

Sort::Sort(int count, int values[])
{
   this->count = count;
   this->values = new int[count];
   for (int i = 0; i < count; ++i)
      this->values[i] = values[i];
}

Sort::Sort(int count, ...)
{
   this->count = count;
   this->values = new int[count];
   
   va_list args;
   va_start(args, count);

   for (int i = 0; i < count; ++i)
      this->values[i] = va_arg(args, int);

   va_end(args);
}

Sort::Sort(char string[])
{
   int count = 1, length;
   for (length = 0; string[length]; ++length)
      if (string[length] == ',')
         count++;
   
   this->count = count;
   this->values = new int[count] { };

   int idx = 0;
   bool sign = 0;
   for (int i = 0; i <= length; ++i)
   {
      if (string[i] == ',' || string[i] == 0)
      {
         if (sign)   this->values[idx] = -this->values[idx];
         idx++;
         sign = 0;
      }
      else
      {
         if (string[i] == '-')
            sign = 1;
         else
            this->values[idx] = this->values[idx] * 10 + (string[i] - '0');
      }
   }
}

Sort::~Sort()
{
   if (values)
      delete[] values;
}


void Sort::InsertSort(bool ascendent)
{
   for (int i = 1; i < this->count; ++i)
      for (int j = i-1; j >= 0; --j)
         if ((ascendent && this->values[j] > this->values[j+1])
               || (!ascendent && this->values[j] < this->values[j+1]))
            std::swap(this->values[j], this->values[j+1]);
         else
            break;
}

void Sort::_QuickSort(int st, int dr, bool ascendent, std::random_device &rd)
{
   std::uniform_int_distribution<int> dist(st, dr);
   int pivot = this->values[dist(rd)];

   int left = st, right = dr;
   while (left <= right)
   {
      while ((ascendent && this->values[left] < pivot) || (!ascendent && this->values[left] > pivot))
         left++;
      while ((ascendent && this->values[right] > pivot) || (!ascendent && this->values[right] < pivot))
         right--;

      if (left <= right)
      {
         std::swap(this->values[left], this->values[right]);
         left++;
         right--;
      }

      if (st < right)
         _QuickSort(st, right, ascendent, rd);
      if (left < dr)
         _QuickSort(left, dr, ascendent, rd);
   }
}

void Sort::QuickSort(bool ascendent)
{
   std::random_device rd;
   this->_QuickSort(0, this->count - 1, ascendent, rd);
}

void Sort::BubbleSort(bool ascendent)
{
   bool sorted;
   do {
      sorted = true;
      for (int i = 1; i < this->count; ++i)
      {
         if ((ascendent && this->values[i-1] > this->values[i])
               || (!ascendent && this->values[i-1] < this->values[i]))
         {
            sorted = false;
            std::swap(this->values[i-1], this->values[i]);
         }
      }
   } while (!sorted);
}

void Sort::Print()
{
   for (int i = 0; i < this->count; ++i)
      std::cout << this->values[i] << ' ';
   std::cout << '\n';
}

int Sort::GetElementsCount()
{
   return this->count;
}

int Sort::GetElementFromIndex(int index)
{
   return this->values[index];
}