#include "Canvas.h"

int main()
{
   Canvas canvas(80, 20);

   canvas.FillRect(-100, -100, 100, 100, '!');
   canvas.DrawRect(23, 1, 70, 14, '@');
   canvas.SetPoint(45, 7, '-');
   canvas.SetPoint(44, 8, '-');
   canvas.SetPoint(46, 8, '-');

   canvas.Print();
   
   canvas.Clear();

   canvas.DrawLine(0, 0, 79, 0, '9');
   canvas.DrawLine(79, 0, 79, 19, '8');
   canvas.DrawLine(79, 19, 0, 0, '7');
   canvas.DrawLine(79, 0, 62, 15, '6');
   canvas.DrawCircle(34, 9, 9, '%');
   canvas.FillCircle(34, 9, 4, '#');

   canvas.Print();
}