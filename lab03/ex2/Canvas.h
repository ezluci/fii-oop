#pragma once

// point (0, 0) is on the top-left corner
class Canvas
{
private:
   int width, height;
   char** matrix;
public:
   Canvas(int width, int height);
   void DrawCircle(int xc, int yc, int ray, char ch);
   void FillCircle(int xc, int yc, int ray, char ch);
   void DrawRect(int left, int top, int right, int bottom, char ch);
   void FillRect(int left, int top, int right, int bottom, char ch);
   void SetPoint(int x, int y, char ch);
   void DrawLine(int x1, int y1, int x2, int y2, char ch);
   void Print(); // shows what was printed
   void Clear(); // clears the canvas
};