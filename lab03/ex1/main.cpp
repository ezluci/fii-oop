#include <iostream>
#include "Math.h"

int main()
{
   std::cout << Math::Add(1, 2) << ' ' << Math::Add(1, 2, 3) << '\n';
   std::cout << Math::Add(1.3, 2.3) << ' ' << Math::Add(1.3, 2.3, 3.3) << '\n';
   
   std::cout << Math::Mul(1, 2) << ' ' << Math::Mul(1, 2, 3) << '\n';
   std::cout << Math::Mul(1.3, 2.3) << ' ' << Math::Mul(1.3, 2.3, 3.3) << '\n';
   
   std::cout << Math::Add(5,  1, 2, 3, 4, 5) << '\n';
   
   std::cout << Math::Add("1245244252452", "56983926836236526390") << '\n';
   std::cout << Math::Add("56983926836236526390", "56983926836236526390") << '\n';
}