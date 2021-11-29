#include "Equilateral.h"
#include <math.h>

	Equilateral::Equilateral(double x) : Triangle(x, 0, 0, 0) {
		Line temp(x, 0, 0, 0);
		length = temp.length();
		equiCount++;
	}
	
	double Equilateral::calculateArea(){
		return (sqrt(3) / 4) * length * length;
	}
	
	double Equilateral::calculatePerimeter(){
		return length*3;
	}
	

