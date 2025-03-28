#include "Number.h"
#include <cstring>
#include <iostream>

int convertToDec(Number num)
{
   int result = 0, p = 1;
   for (int i = num.GetDigitsCount() - 1; i >= 0; i--)
   {
      int digit;
      if ('A' <= num[i] && num[i] <= 'F') digit = num[i] - 'A' + 10;
      else  digit = num[i] - '0';
      result += digit * p;
      p *= num.GetBase();
   }
   return result;
}

char* convertToBase(int num, int base)
{
   int digits = 0;
   int num2 = num;
   for (; num2; num2 /= base)
      ++digits;

   char *result = new char[digits + 1];
   result[digits] = 0;
   int i = 0;

   for (; num; num /= base, ++i)
   {
      char digit = num % base;
      if (digit >= 10)  digit = digit - 10 + 'A';
      else  digit += '0';
      result[digits - i - 1] = digit;
   }
   return result;
}

Number::Number(const char *value, int base)
{
   this->value = new char[strlen(value) + 1];
   strcpy(this->value, value);
   this->base = base;
   this->digitsCount = strlen(value);
}

Number::Number(int value)
{
   this->value = convertToBase(value, 10);
   this->base = 10;
   this->digitsCount = strlen(this->value);
}

Number::Number(const char *value)
{
   this->value = new char[strlen(value) + 1];
   strcpy(this->value, value);
   this->base = 10;
   this->digitsCount = strlen(value);
}

Number::~Number()
{
   delete[] this->value;
}

Number::Number(const Number &num)
{
   this->value = new char[num.digitsCount + 1];
   strcpy(this->value, num.value);
   this->base = num.base;
   this->digitsCount = num.digitsCount;
}

Number::Number(Number &&num)
{
   this->value = num.value;
   this->base = num.base;
   this->digitsCount = num.digitsCount;
   num.value = nullptr;
}

Number operator+ (const Number &A, const Number &B)
{
   int base = A.base;
   int A_dec = convertToDec(A), B_dec = convertToDec(B);
   char* result = convertToBase(A_dec + B_dec, base);
   return Number(result, base);
}

Number operator- (const Number &A, const Number &B)
{
   int base = A.base;
   int A_dec = convertToDec(A), B_dec = convertToDec(B);
   char* result = convertToBase(A_dec - B_dec, base);
   return Number(result, base);
}

char Number::operator[] (int index)
{
   return this->value[index];
}

bool Number::operator> (const Number &other)
{
   int number1 = convertToDec(*this), number2 = convertToDec(other);
   return number1 > number2;
}

bool Number::operator< (const Number &other)
{
   int number1 = convertToDec(*this), number2 = convertToDec(other);
   return number1 < number2;
}

bool Number::operator>= (const Number &other)
{
   int number1 = convertToDec(*this), number2 = convertToDec(other);
   return number1 >= number2;
}

bool Number::operator<= (const Number &other)
{
   int number1 = convertToDec(*this), number2 = convertToDec(other);
   return number1 <= number2;
}

bool Number::operator== (const Number &other)
{
   int number1 = convertToDec(*this), number2 = convertToDec(other);
   return number1 == number2;
}

bool Number::operator!= (const Number &other)
{
   int number1 = convertToDec(*this), number2 = convertToDec(other);
   return number1 != number2;
}

Number Number::operator=(const Number &other)
{
   if (this == &other)  return *this;
   
   delete[] this->value;
   this->value = new char[other.digitsCount + 1];
   strcpy(value, other.value);
   this->base = other.base;
   this->digitsCount = other.digitsCount;
   return *this;
}

Number Number::operator--()
{
   for (int i = 0; i < this->digitsCount - 1; ++i)
      this->value[i] = this->value[i+1];
   this->value[this->digitsCount - 1] = 0;
   this->digitsCount -= 1;
   return *this;
}

Number Number::operator--(int)
{
   this->value[this->digitsCount - 1] = 0;
   this->digitsCount -= 1;
   return *this;
}

Number Number::operator+=(const Number &other)
{
   int base = this->base;
   int A_dec = convertToDec(*this), B_dec = convertToDec(other);
   int sum = A_dec + B_dec;
   char* result = convertToBase(sum, base);
   delete[] this->value;
   this->value = result;
   this->digitsCount = strlen(this->value);
   return *this;
}

void Number::SwitchBase(int newBase)
{
   int number = convertToDec(*this);
   char* result = convertToBase(number, newBase);
   digitsCount = strlen(result);
   delete[] this->value;
   this->value = result;
   this->base = newBase;
}

void Number::Print()
{
   std::cout << value << '\n';
}

int Number::GetBase()
{
   return this->base;
}

int Number::GetDigitsCount()
{
   return this->digitsCount;
}