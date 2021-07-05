#include <iostream>
#include <string>
using namespace std;

class Date{
private:
	unsigned int day, month, year;

public:
	Date(){
		day = month = year = 1;
	}
	Date(int d, int m, int y){
		day = d;
		month = m;
		year = y;
	}	
	
	
	void setDay(int d){
		day = d;
	}
	int getDay(){
		return day;
	}
	void setMonth(int m){
		month = m;
	}
	int getMonth(){
		return month;
	}
	void setYear(int y){
		year = y;
	}
	int getYear(){
		return year;
	}
	
	bool isSmaller(Date D){
		if(D.getYear() > year)
			return true;
		if(D.getMonth() > month)
			return true;
		if(D.getDay() > day)
			return true;
		return false; 
	}
	
	friend ostream &operator << (ostream &o, Date &d);
	friend istream &operator >> (istream &i, Date &d);
};

ostream &operator << (ostream &o, Date &d){
	o << d.day << "/" << d.month << "/" << d.year;
	return o;
}
istream &operator >> (istream &i, Date &d){
	cout << "Enter day, month and year: ";
	i >> d.day >> d.month >> d.year;
	return i;	
}


int main(int argc, char** argv) {
	Date yearOne, yearTwo(31, 5, 2001);
	
	cout << "yearOne: " << yearOne << endl;
	cout << "yearTwo: " << yearTwo << endl;
	
	yearOne.setDay(23);
	yearOne.setMonth(3);
	yearOne.setYear(1965);
	cout << "yearOne after re-set: " << yearOne << endl;
	
	if(yearOne.isSmaller(yearTwo))
		cout << "yearTwo: " << yearTwo << endl;
	else
		cout << "yearOne: " << yearOne << endl;
		
	Date dateThree;
	cin >> dateThree;
	cout << "dateThree: " << dateThree;
		
	return 0;
}
