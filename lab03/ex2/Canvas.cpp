#include "Canvas.h"
#include <iostream>
#include <cmath>

Canvas::Canvas(int width, int height)
{
   if (width < 0) width = 0;
   if (height < 0)   height = 0;

   this->width = width;
   this->height = height;

   matrix = new char*[width];
   for (int i = 0; i < width; ++i)
   {
      matrix[i] = new char[height];
      for (int j = 0; j < height; ++j)
         matrix[i][j] = ' ';
   }
}

void Canvas::DrawCircle(int xc, int yc, int ray, char ch)
{
   for (int x = 0; x < this->width; ++x)
      for (int y = 0; y < this->height; ++y)
      {
         int length = (x - xc) * (x - xc) + (y - yc) * (y - yc);
         if (ray * (ray-1) <= length && length <= ray * (ray+1))
            this->SetPoint(x, y, ch);
      }
}

void Canvas::FillCircle(int xc, int yc, int ray, char ch)
{
   for (int x = 0; x < this->width; ++x)
      for (int y = 0; y < this->height; ++y)
      {
         int length = (x - xc) * (x - xc) + (y - yc) * (y - yc);
         if (length <= ray * ray)
            this->SetPoint(x, y, ch);
      }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
   for (int i = std::max(left, 0); i <= std::min(right, this->width - 1); ++i)
      this->matrix[i][top] = this->matrix[i][bottom] = ch;
   for (int i = std::max(top, 0); i <= std::min(bottom, this->height - 1); ++i)
      this->matrix[left][i] = this->matrix[right][i] = ch;
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
   for (int i = std::max(left, 0); i <= std::min(right, this->width - 1); ++i)
      for (int j = std::max(top, 0); j <= std::min(bottom, this->height - 1); ++j)
         this->matrix[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch)
{
   if (0 <= x && x < this->width && 0 <= y && y < this->height)
      this->matrix[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
   int p = x1 * y2 - x2 * y1;
   int dx = x2 - x1, dy = y2 - y1;
   if (x1 > x2)   std::swap(x1, x2);
   if (y1 > y2)   std::swap(y1, y2);

   for (int y = y1; y <= y2; ++y)
   {
      int x = round((double) (dx * y + p) / dy);
      this->SetPoint(x, y, ch);
   }
   for (int x = x1; x <= x2; ++x)
   {
      int y = round((double) (dy * x - p) / dx);
      this->SetPoint(x, y, ch);
   }
}

void Canvas::Print()
{
   for (int y = 0; y < this->height; ++y)
   {
      for (int x = 0; x < this->width; ++x)
         std::cout << this->matrix[x][y];
      std::cout << '\n';
   }
   std::cout << '\n';
}

void Canvas::Clear()
{
   for (int x = 0; x < this->width; ++x)
      for (int y = 0; y < this->height; ++y)
         this->matrix[x][y] = ' ';
}