#include <bits/stdc++.h>

using namespace std;

template<class T> 
void sorteaza(T* v,int n,int(compare)(T,T))
{
   bool ok=1;
   do
   {
      ok=false;
      for(int i=0;i+1<n;i++)
         if(!compare(v[i],v[i+1]))
         {
            swap(v[i],v[i+1]);
            ok=1;
         }
   } while(ok);
}

int comp(int a,int b)
{
   return a<=b;
}
int main()
{
   for (int i = 0; i < 100000; ++i)
   {
      int n = rand() % 100 + 1;
      int* v = new int[n];
      for (int i = 0; i < n; ++i)
         v[i] = rand() % 200;
      int *vc = new int[n];
      for (int i = 0; i < n; ++i)   vc[i] = v[i];
      std::sort(vc, vc+n);
      sorteaza(v, n, comp);
      std::cout << n << '\n';
      for (int i = 0; i < n; ++i)   std::cout << v[i] << ' ';
      std::cout << '\n';
      for (int i = 0; i < n; ++i)   std::cout << vc[i] << ' ';
      std::cout << '\n';
      for (int i = 0; i < n; ++i)
         assert(v[i] == vc[i]);

      delete[] v;
      delete[] vc;
   }
   return 0;
}