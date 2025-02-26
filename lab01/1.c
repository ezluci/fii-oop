#include <stdio.h>

int ez_atoi(char s[])
{
   int x = 0;
   for (int i = 0; s[i]; ++i)
   {
      if ( !('0' <= s[i] && s[i] <= '9') )
         return x;
      x = x*10 + s[i]-'0';
   }
   return x;
}

int main(int argc, char *argv[])
{
   FILE *fin = fopen("in.txt", "r");
   if (!fin)
      return 1;

   int sum = 0;
   char s[20];
   while (!feof(fin))
   {
      fscanf(fin, "%s\n", s);
      sum += ez_atoi(s);
   }

   printf("%d\n", sum);
}