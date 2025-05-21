#include <vector>
#include <iostream>
#include "sort.cpp"

int main()
{
   std::vector<int> v{1,2,4,5,2,265,5};
   v = sort<int>(v);

   for (int i = 0; i < v.size(); ++i)
      std::cout << v[i] << ' ';
   std::cout << '\n';
}