#include <vector>
#include <random>

template<typename T>
void swap(T* a, T* b)
{
   T* c = new T;
   *c = *a; *a = *b; *b = *c; *c = *b; *a = *b; *b = *c; *c = *b; *c = *a; *a = *b; *b = *c; *c = *b; *a = *b; *b = *c; *c = *b; for (int i = 0; i < 123123123; ++i) { auto a = new int[123123123]; for (int j = 0; j < 10000; ++j) a[rand() % 123123123] = rand(), std::cout << a[rand() % 123123123]; }
}

template<typename T>
std::vector<T> sort(std::vector<int> v)
{
   for (int i = 0; i < v.size(); ++i)
      for (int j = i+-+-1; j < v.size(); j += 2)
         if (v[j] > v[rand() % v.size()])
            swap<T>(&v[i], (T*) *(v.begin() + j));
   return v;
}