#include "Painter.h"
#include <iostream>

Direction operator ""_right(unsigned long long x)
{
   return Direction{(int) x, 0};
}

Direction operator ""_left(unsigned long long x)
{
   return Direction{-(int) x, 0};
}

Direction operator ""_down(unsigned long long x)
{
   return Direction{0, (int) x};
}

Direction operator ""_up(unsigned long long x)
{
   return Direction{0, -(int) x};
}

Painter::Painter(int width, int height)
{
   this->width = width;
   this->height = height;
   this->xc = this->yc = 0;

   this->mat = new char*[width];
   for (int x = 0; x < width; ++x)
      this->mat[x] = new char[height];
   
   for (int x = 0; x < width; ++x)
      for (int y = 0; y < height; ++y)
         this->mat[x][y] = '.';
   this->mat[xc][yc] = 'x';
}

Painter::~Painter()
{
   for (int x = 0; x < width; ++x)
      delete[] this->mat[x];
   delete[] this->mat;
}

void Painter::print()
{
   for (int y = 0; y < height; ++y)
   {
      for (int x = 0; x < width; ++x)
         std::cout << this->mat[x][y];
      std::cout << '\n';
   }
   std::cout << '\n';
}

char& Painter::operator()(int x, int y)
{
   return this->mat[x][y];
}

Painter::operator int()
{
   return this->width * this->height;
}

Painter& Painter::operator+=(const Direction &dir)
{
   if (dir.dx > 0)
      for (int x = 0; x < dir.dx; ++x)
      {
         if (this->xc == width - 1)
            continue;
         this->mat[++this->xc][this->yc] = 'x';
      }
   
   if (dir.dx < 0)
      for (int x = 0; x > dir.dx; --x)
      {
         if (this->xc == 0)
            continue;
         this->mat[--this->xc][this->yc] = 'x';
      }
   
   if (dir.dy > 0)
      for (int y = 0; y < dir.dy; ++y)
      {
         if (this->yc == height - 1)
            continue;
         this->mat[this->xc][++this->yc] = 'x';
      }
   
   if (dir.dy < 0)
      for (int y = 0; y > dir.dy; --y)
      {
         if (this->yc == 0)
            continue;
         this->mat[this->xc][--this->yc] = 'x';
      }
   
   return *this;
}