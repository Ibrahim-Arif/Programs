#include<iostream>
using namespace std;

class Employee{
public:
	string name, education;
	int age, contact, cnic;
}; 

class Permanent_EMP : public Employee {
public:
	int basic_salary, allowances;
	
	Permanent_EMP(int bs, int a){
		basic_salary = bs;
		allowances = a;
	}
	
	int calculate_salary(){
		return basic_salary + allowances;
	}
};

class Contractual_EMP : public Employee {
public:
	int basic_salary, commission_percentage;
	
	Contractual_EMP(int bs, int cp){
		basic_salary = bs;
		commission_percentage = cp;
	}
	
	int calculate_salary(){
		return  basic_salary + (basic_salary* commission_percentage/100);
	}
};

int main()               

{
	Contractual_EMP ce(12000, 15);
	Permanent_EMP pe(70000, 20000);
	
    cout << "Please enter data for Permanent_EMP" << endl;
    cout << "Enter name: ";
    getline(cin, pe.name);
   
    cout << "Enter education: ";
    getline(cin, pe.education);
   
    cout << "Enter age: ";
    cin >> pe.age;
   
    cout << "Enter contact: ";
    cin >> pe.contact;
   
    cout << "Enter CNIC: ";
    cin >> pe.cnic;
   
   
	cout << "\nPlease enter data for Contractual_EMP" << endl;
    cout << "Enter name: ";
    getline(cin, ce.name);
   
    cout << "Enter education: ";
    getline(cin, ce.education);
   
    cout << "Enter age: ";
    cin >> ce.age;
   
    cout << "Enter contact: ";
    cin >> ce.contact;
   
    cout << "Enter CNIC: ";
    cin >> pe.cnic;
    
    cout << "\n---- DATA FOR Permanent_EMP ----" << endl;
    cout << "Name: " << pe.name << endl;
	cout << "Education: " << pe.education << endl;
	cout << "Age: " << pe.age << endl;
	cout << "Contact: " << pe.contact << endl;
	cout << "CNIC: " << pe.cnic << endl;
	cout << "Calculated salary: " << pe.calculate_salary() << endl;
	
	
	cout << "\n---- DATA FOR Contractual_EMP ----" << endl;
    cout << "Name: " << ce.name << endl;
	cout << "Education: " << ce.education << endl;
	cout << "Age: " << ce.age << endl;
	cout << "Contact: " << ce.contact << endl;
	cout << "CNIC: " << ce.cnic << endl;
	cout << "Calculated salary: " << ce.calculate_salary() << endl;
	
	return 0;
}
