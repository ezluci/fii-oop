#pragma once

struct Direction {
   int dx, dy;
};

Direction operator ""_right(unsigned long long x);
Direction operator ""_left(unsigned long long x);
Direction operator ""_down(unsigned long long x);
Direction operator ""_up(unsigned long long x);

class Painter {
private:
   int width, height;
   int xc, yc;
   char **mat;
public:
   Painter(int width, int height);
   ~Painter();
   void print();
   char& operator()(int x, int y);
   operator int();
   Painter& operator+=(const Direction &dir);
};