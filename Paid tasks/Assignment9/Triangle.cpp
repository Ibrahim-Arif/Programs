#include "Triangle.h"
#include <math.h>

Triangle::Triangle(double ax, double ay, double bx, double by){
	a.setx(ax);
	a.sety(ay);
		
	b.setx(bx);
	b.sety(by);
		
	c.setx(0);
	c.sety(0);
		
	triCount++;
}


double Triangle::calculateArea(){
	double area = 0;
	double sum = 0;
		
	Line lineAtoB(a, b);
	Line lineAtoC(a, c);
	Line lineBtoC(b, c);
		
	double lengthA = lineAtoB.length();
	double lengthB = lineAtoC.length();
	double lengthC = lineBtoC.length();
		
	sum =  lengthA + lengthB + lengthC;
	sum /= 2;
		
	area = sqrt(sum * (sum - lengthA) * (sum - lengthB) * (sum - lengthC));
	return area;
}

double Triangle::calculatePerimeter(){
	double sum=0;
		
	Line lineAtoB(a, b);
	Line lineAtoC(a, c);
	Line lineBtoC(b, c);
		
	double lengthA = lineAtoB.length();
	double lengthB = lineAtoC.length();
	double lengthC = lineBtoC.length();
		
	sum =  lengthA + lengthB + lengthC;
		
	return sum;
}
