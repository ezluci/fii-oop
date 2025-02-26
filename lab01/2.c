#include <stdio.h>
#include <stdlib.h>

// -1 -> s1<s2   0 -> s1=s2   1 -> s1>s2
int ezCompareStrings(const void *S1, const void *S2)
{
   char *s1 = *(char**) S1, *s2 = *(char**) S2;

   int len1, len2;
   for (len1 = 0; s1[len1]; ++len1);
   for (len2 = 0; s2[len2]; ++len2);

   if (len1 > len2)  return -1;
   if (len1 < len2)  return +1;

   // len1 == len2
   for (int i = 0; i < len1; ++i)
   {
      if (s1[i] < s2[i])   return -1;
      if (s1[i] > s2[i])   return +1;
   }

   return 0;
}


int main(int argc, char *argv[])
{
   char s[10000];
   
   int len = 0;  char c;
   while ((c = getc(stdin)) && c != EOF && c != '\n')
      s[len++] = c;
   s[len] = 0;

   char* cuvinte[10000];
   int cuvinteLen = 0;

   int i = 0;

   while (i < len)
   {
      while (i < len && s[i] == ' ')   i++;

      int j = i;
      while (j < len && s[j] != ' ')   j++;

      cuvinte[cuvinteLen] = malloc(j-i+1);
      for (int h = 0; i+h < j; ++h) cuvinte[cuvinteLen][h] = s[i+h];
      cuvinte[cuvinteLen][j-i] = 0;

      cuvinteLen++;
      i = j;
   }

   qsort(cuvinte, cuvinteLen, sizeof(char*), ezCompareStrings);

   for (int i = 0; i < cuvinteLen; ++i)
      printf("%s\n", cuvinte[i]);
}