#include <stdio.h>
#include <string.h>

int ez_atoi(char s[])
{
   int x = 0;
   for (int i = 0; s[i]; ++i)
   {
      if ( !('0' <= s[i] && s[i] <= '9') ) {
         
      }
      x = x*10 + s[i]-'0';
   }
   return x;
}

int main(int argc, char *argv[])
{
   char a[10] = {}, b[10] = {};

   FILE *fin = fopen("in.txt", "r");
   if (!fin) {
      return 1;
   }

   fscanf(fin, "%s\n%s", a, b);

   int A = ez_atoi(a), B = ez_atoi(b);

   printf("%d\n", A + B);
}