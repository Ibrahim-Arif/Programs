#include <iostream>
#include <fstream>
#include "Triangle.cpp"
#include "Equilateral.cpp"

using namespace std;

int Triangle::triCount = 1;
int Equilateral::equiCount = 1;

void print_Tri_details(Triangle t){
	cout << "A(" << t.a.getx() << ", " << t.a.gety() << "), "; 
	cout << "B(" << t.b.getx() << ", " << t.b.gety() << "), "; 
	cout << "C(" << t.c.getx() << ", " << t.c.gety() << ")" << endl; 
}

void print_Equi_details(Equilateral e){
	cout<<"Length of Equilateral: " << e.length << endl;
}


int main(){
	double x1, y1, x2, y2;
	cout << "Enter x1: ";
	cin >> x1;
	cout << "Enter y1: ";
	cin >> y1;
	cout << "Enter x2: ";
	cin >> x2;
	cout << "Enter y2: ";
	cin >> y2;

	cout << "\n--- Triangles Details ---" << endl;
	Triangle first(x1, y1, x2, y2);
	print_Tri_details(first);
	
	
	ifstream file("comp20080-autumn2021-Asst9-data.txt");
	double temp = 0.0;
	file >> x1;
	file >> y1;
	file >> x2;
	file >> y2;
	
	Triangle second(x1, y1, x2, y2);
	print_Tri_details(second);
	
	cout << endl;
	if(first.calculateArea() == 0){
		cout << "First triangle is trivial." << endl;
	}else{
		cout << "--- First Triangle ---" << endl;
		cout << "Area: " << first.calculateArea() << endl;
		cout << "Perimeter: " << first.calculatePerimeter() << endl;
	}
	
	cout << endl;
	if(second.calculateArea() == 0){
		cout << "Second triangle is trivial." << endl;
	}else{
		cout << "--- Second Triangle ---" << endl;
		cout << "Area: " << second.calculateArea() << endl;
		cout << "Perimeter: " << second.calculatePerimeter() << endl;
	}
	
	cout << "\nEnter x (Equilateral): ";
	cin >> x1;
	
	Equilateral e(x1);
	print_Equi_details(e);
	
	cout << "\n--- Equilateral Triangle ---" << endl;
	cout << "Area: " << e.calculateArea() << endl;
	cout << "Perimeter: " << e.calculatePerimeter() << endl;
	
	cout << "\n--- Triangles Count ---" << endl;
	cout << "Total triangles: " << first.triCount << endl;
	cout << "Total equilateral: " << e.equiCount << endl;
	
	return 0;

}
