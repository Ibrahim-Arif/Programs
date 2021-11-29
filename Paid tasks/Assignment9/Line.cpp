#include "Point.h"
#include "Line.h"
#include <math.h>

Line::Line(Point& p1, Point& p2)
{
  a=p1; b=p2;
}

Line::Line(double x1, double y1, double x2, double y2)
{
  Point p(x1,y1); Point q(x2,y2);
  a=p; b=q;
}

double Line::length()
{
  return sqrt((a.getx()-b.getx())*(a.getx()-b.getx()) + (a.gety()-b.gety())*(a.gety()-b.gety()));
}
