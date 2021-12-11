#ifndef EQUILATERAL_H
#define EQUILATERAL_H

#include "Triangle.h"

class Equilateral : public Triangle{
private:
	double length;
	
public:
	static int equiCount;
	Equilateral(double x);
	double calculateArea();
	double calculatePerimeter();
	friend void print_Equi_details(Equilateral e);
};

#endif
