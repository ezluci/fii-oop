#pragma once

class Number
{
   char* value;
   int base, digitsCount;
public:
   Number(const char *value, int base);
   Number(const int value);
   Number(const char *value);
   ~Number();
   Number(const Number &num);
   Number(Number &&num);

   friend Number operator+ (const Number &A, const Number &B);
   friend Number operator- (const Number &A, const Number &B);
   char operator[] (int index);
   bool operator> (const Number &num);
   bool operator< (const Number &num);
   bool operator>= (const Number &num);
   bool operator<= (const Number &num);
   bool operator== (const Number &num);
   bool operator!= (const Number &num);
   Number operator= (const Number &num);

   Number operator-- ();
   Number operator-- (int);
   Number operator+= (const Number &num);

   void SwitchBase(int newBase);
   void Print();
   int  GetDigitsCount(); // returns the number of digits for the current number
   int  GetBase(); // returns the current base
};