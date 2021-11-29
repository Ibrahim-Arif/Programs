#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"
#include "Line.h"

class Triangle{	
private:
	Point a, b, c;
	
public:
	static int triCount;
	Triangle(double ax, double ay, double bx, double by);
	double calculateArea();
	double calculatePerimeter();
	friend void print_Tri_details(Triangle t);
};

#endif
