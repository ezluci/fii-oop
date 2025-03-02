#include "NumberList.h"

int main(int argc, char *argv[])
{
   NumberList list;
   
   // we must initialize the class
   list.Init();

   for (int i = 0; i < 9; ++i)
      if (i & 1)  list.Add(i);
      else  list.Add(-i);
   list.Print();
   
   list.Add(-666); // adds the 10th element
   list.Print();

   list.Add(100); // does not get added (max size exceeded); returns false
   list.Print();

   list.Sort();
   list.Print();
}