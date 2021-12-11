#include "Point.h"

// The first constructor sets the point to the origin (0.0,0.0)
Point::Point()
{
  x=0.0; y=0.0;
}

// The second constructor is given the coordinates as input
Point::Point(double a, double b)
{
  x=a; y=b;
}

double Point::getx()
{
 return x;
}

double Point::gety()
{
 return y;
}

void Point::setx(double a)
{
 x=a;
}

void Point::sety(double b)
{
 y=b;
}
