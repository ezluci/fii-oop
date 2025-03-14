#include "Math.h"
#include <cstdarg>
#include <cstring>
#include <algorithm>

int Math::Add(int a, int b)
{
   return a + b;
}

int Math::Add(int a, int b, int c)
{
   return a + b + c;
}

double Math::Add(double a, double b)
{
   return a + b;
}

double Math::Add(double a, double b, double c)
{
   return a + b + c;
}

int Math::Mul(int a, int b)
{
   return a * b;
}

int Math::Mul(int a, int b, int c)
{
   return a * b * c;
}

double Math::Mul(double a, double b)
{
   return a * b;
}

double Math::Mul(double a, double b, double c)
{
   return a * b * c;
}

int Math::Add(int count, ...)
{
   int sum = 0;
   va_list args;
   va_start(args, count);

   for (int i = 0; i < count; ++i)
      sum += va_arg(args, int);

   va_end(args);
   return sum;
}

char* Math::Add(const char *a, const char *b)
{
   if (!a || !b)
      return nullptr;
   
   int length_a = 0, length_b = 0;
   for (; a[length_a]; ++length_a);
   for (; b[length_b]; ++length_b);
   int length_c = std::max(length_a, length_b) + 1;

   char *c = new char[length_c + 1] { };

   int ia = length_a - 1, ib = length_b - 1, ic = length_c - 1;
   int carry = 0;
   for (; ic >= 0; --ic)
   {
      if (ia >= 0)   carry += a[ia] - '0';
      if (ib >= 0)   carry += b[ib] - '0';
      c[ic] = carry % 10 + '0';
      carry = carry / 10;
      ia--; ib--;
   }

   if (c[0] == '0')
   {
      char *c2 = new char[length_c];
      memcpy(c2, c+1, length_c);
      delete[] c;
      c = c2;
   }
   
   return c;
}