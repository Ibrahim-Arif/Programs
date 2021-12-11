#include <iostream>
using namespace std;

class Product {
public:
    string name, desc, country, fabric, condition, color, size, gender, note;
    double price;
    int age;

    Product(){}
    Product(string name, double price, string desc, string country, string fabric, string condition, string color, string size, string gender, int age, string note){
        this->name = name;
        this->price = price;
        this->desc = desc;
        this->country = country;
        this->fabric = fabric;
        this->condition = condition;
        this->color = color;
        this->size = size;
        this->gender = gender;
        this->age = age;
        this->note = note;
    }

    void print(){
        cout << "----- Product -----" << endl;
        cout << "Name: " << name << endl;
        cout << "Description: " << desc << endl;
        cout << "Price: " << price << endl;
        cout << "Country: " << country << endl;
        cout << "Fabric: " << fabric << endl;
        cout << "Condition: " << condition << endl;
        cout << "Color: " << color << endl;
        cout << "Size: " << size << endl;
        cout << "Gender: " << gender << endl;
        cout << "Note: " << note << endl;
        cout << "Age group: " << age << endl;
        cout << endl;
    }
};

class Person{
public:
    string name, email, DOB, gender;
    int phoneNo;

    Person(){}
    Person(string name, string email, string DOB, int phoneNo, string gender){
        this->name = name;
        this->email = email;
        this->DOB = DOB;
        this->phoneNo = phoneNo;
        this->gender = gender;
    }

    virtual void print(){
        cout << "----- Person -----" << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Date of birth: " << DOB << endl;
        cout << "Phone number: " << phoneNo << endl;
        cout << "Gender: " << gender << endl;
    }
};
class Customer : public Person {
public:
    string address, cardNo;

    Customer() :Person(){}
    Customer(string name, string email, string DOB, int phoneNo, string gender, string address, string cardNo) :Person(name, email, DOB, phoneNo, gender){
        this->address = address;
        this->cardNo = cardNo;
    }

    void print(){
        cout << "----- Customer -----" << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Date of birth: " << DOB << endl;
        cout << "Phone number: " << phoneNo << endl;
        cout << "Gender: " << gender << endl;
        cout << "Address: " << address << endl;
        cout << "Card number: " << cardNo << endl;
        cout << endl;
    }
};

class Employee : public Person{
public:
    string civilId, nationaltiy;
    double salary;

    Employee() :Person(){}
    Employee(string name, string email, string DOB, int phoneNo, string gender, string civilId, string nationaltiy, double salary) :Person(name, email, DOB, phoneNo, gender){
        this->civilId = civilId;
        this->nationaltiy = nationaltiy;
        this->salary = salary;
    }

    virtual void incrementSalary(double percent){
        salary += (salary * percent/100);
    }

    void print(){
        cout << "----- Employee -----" << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Email: " << email << endl;
        cout << "Date of birth: " << DOB << endl;
        cout << "Phone number: " << phoneNo << endl;
        cout << "Gender: " << gender << endl;
        cout << "Civil ID: " << civilId << endl;
        cout << "Nationality: " << nationaltiy << endl;
        cout << endl;
    }

};
class Driver : public Employee {
public:
    int drivingLicenseNo;

    Driver():Employee(){}
    Driver(string name, string email, string DOB, int phoneNo, string gender, string civilId, string nationaltiy, double salary, int drivingLicenseNo):Employee(name, email, DOB, phoneNo, gender, civilId, nationaltiy, salary){
        this->drivingLicenseNo = drivingLicenseNo;
    }

    void print(){
        cout << "----- Driver -----" << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Email: " << email << endl;
        cout << "Date of birth: " << DOB << endl;
        cout << "Phone number: " << phoneNo << endl;
        cout << "Gender: " << gender << endl;
        cout << "Civil ID: " << civilId << endl;
        cout << "Nationality: " << nationaltiy << endl;
        cout << "Driving license number: " << drivingLicenseNo << endl;
        cout << endl;
    }
};
class SalesMan : public Employee {
public:
    int successfulSales;

    SalesMan():Employee(){}
    SalesMan(string name, string email, string DOB, int phoneNo, string gender, string civilId, string nationaltiy, double salary, int successfulSales):Employee(name, email, DOB, phoneNo, gender, civilId, nationaltiy, salary){
        this->successfulSales = successfulSales;
    }

    void incrementSalary(double percent){
        if(successfulSales < 6)
            return;

        if(successfulSales < 11)
            salary += (salary * 0.2);
        else
            salary += (salary * 0.5);
    }

    void print(){
        cout << "----- SalesMan -----" << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Email: " << email << endl;
        cout << "Date of birth: " << DOB << endl;
        cout << "Phone number: " << phoneNo << endl;
        cout << "Gender: " << gender << endl;
        cout << "Civil ID: " << civilId << endl;
        cout << "Nationality: " << nationaltiy << endl;
        cout << "Successful sales: " << successfulSales << endl;
        cout << endl;
    }
};

class Manager : public Employee {
public:
    double bonus;

    Manager():Employee(){}
    Manager(string name, string email, string DOB, int phoneNo, string gender, string civilId, string nationaltiy, double salary, double bonus):Employee(name, email, DOB, phoneNo, gender, civilId, nationaltiy, salary){
        this->bonus = bonus;
    }

    bool increaseEmployeeSalary(Employee *employees[10], string name, string civilId, double percent){
        int i;
        bool found = false;

        for(i=0; i<10; i++){
            if(employees[i] == NULL)
                break;

            if(employees[i]->name == name && employees[i]->civilId == civilId){
                found = true;
                employees[i]->incrementSalary(percent);
            }
        }

        return found;
    }

    void print(){
        cout << "----- Manager -----" << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Email: " << email << endl;
        cout << "Date of birth: " << DOB << endl;
        cout << "Phone number: " << phoneNo << endl;
        cout << "Gender: " << gender << endl;
        cout << "Civil ID: " << civilId << endl;
        cout << "Nationality: " << nationaltiy << endl;
        cout << "Bonus: " << bonus << endl;
        cout << endl;
    }

};
class DriverManager : public Manager {
public:
    int drivingLicenseNo;

    DriverManager():Manager(){}
    DriverManager(string name, string email, string DOB, int phoneNo, string gender, string civilId, string nationaltiy, double salary, double bonus, int drivingLicenseNo):Manager(name, email, DOB, phoneNo, gender, civilId, nationaltiy, salary, bonus){
        this->drivingLicenseNo = drivingLicenseNo;
    }

    void print(){
        cout << "----- DriverManager -----" << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Email: " << email << endl;
        cout << "Date of birth: " << DOB << endl;
        cout << "Phone number: " << phoneNo << endl;
        cout << "Gender: " << gender << endl;
        cout << "Civil ID: " << civilId << endl;
        cout << "Nationality: " << nationaltiy << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Driving license number: " << drivingLicenseNo << endl;
        cout << endl;
    }
};
class SalesManManager : public Manager {
public:
    int successfulSales;

    SalesManManager():Manager(){}
    SalesManManager(string name, string email, string DOB, int phoneNo, string gender, string civilId, string nationaltiy, double salary, double bonus, int successfulSales):Manager(name, email, DOB, phoneNo, gender, civilId, nationaltiy, salary, bonus){
        this->successfulSales = successfulSales;
    }

    void print(){
        cout << "----- SalesManManager -----" << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Email: " << email << endl;
        cout << "Date of birth: " << DOB << endl;
        cout << "Phone number: " << phoneNo << endl;
        cout << "Gender: " << gender << endl;
        cout << "Civil ID: " << civilId << endl;
        cout << "Nationality: " << nationaltiy << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Successful sales: " << successfulSales << endl;
        cout << endl;
    }
};


void initializeProducts(Product *products[10]){
    // female products
    products[0] = new Product("jeans pent", 1200, "Short jeans pent for casual use.", "Canada", "jeans", "good", "blue", "medium", "female", 25, "it's a flexible, anti-dust pent");
    products[1] = new Product("lipstick", 340, "Morning use lipstick.", "England", "", "excellent", "red", "", "female", 30, "It has a 8 hour warranty");
    products[2] = new Product("liplose", 100, "for daily routine use this liplose, it will make your lips shine like a diamond :) ", "England", "", "excellent", "pink", "", "female", 18, "It has a 8 hour warranty");
    products[3] = new Product("eyeliner", 150, "Party use eyeliner.", "England", "", "excellent", "black", "", "female", 20, "It has a 8 hour warranty");
    products[4] = new Product("BB cream", 50, "Casual use cream", "England", "", "good", "white", "", "female", 15, "It has a 8 hour warranty");

    // male products
    products[5] = new Product("jeans", 500, "Jeans for men daily use.", "USA", "jeans", "excellent", "blue", "large", "male", 20, "washable");
    products[6] = new Product("T shirt", 300, "Summer t-shirt.", "France", "poly cotton", "excellent", "blue", "medium", "male", 15, "washable");
    products[7] = new Product("casual shirt", 750, "Offine use decent shirt.", "Germany", "cotton", "excellent", "light green", "large", "male", 20, "washable");
    products[8] = new Product("jacket", 1500, "Leather jacket for winter nights.", "USA", "leather", "excellent", "black", "large", "male", 20, "washable");
    products[9] = NULL;
}
void initializeEmployees(Employee *employees[10]){
    employees[0] = new SalesMan("jason", "jason@gmail.com", "31-5-2000", 123456789, "male", "123-321", "german", 60000, 12);
    employees[1] = new SalesMan("statham", "statham@gmail.com", "31-5-2000", 123456789, "male", "123-322", "england", 23000, 7);
    employees[2] = new SalesMan("jessica", "jessica@gmail.com", "31-5-2000", 123456789, "female", "123-3222", "brazil", 12500, 3);
    employees[3] = new Driver("tom", "tom@gmail.com", "31-5-2000", 123456789, "male", "123-323", "france", 12000, 123456);
    employees[4] = new Driver("cruise", "cruise@gmail.com", "31-5-2000", 123456789, "male", "123-324", "italy", 3000, 545321);

    int i;
    for(i=5; i<10; i++)
        employees[i] = NULL;
}
void initializeManagers(Manager *managers[10]){
    managers[0] = new Manager("win", "win@gmail.com", "31-5-2000", 123456789, "male", "123-325", "USA", 120000, 12500);
    managers[1] = new Manager("diesel", "diesel@gmail.com", "31-5-2000", 123456789, "male", "123-326", "mexico", 110500, 7500);

    managers[2] = new DriverManager("brad", "brad@gmail.com", "31-5-2000", 123456789, "male", "123-327", "australia", 150000, 12000, 734720);
    managers[3] = new SalesManManager("pitt", "pitt@gmail.com", "31-5-2000", 123456789, "male", "123-328", "new zealand", 50300, 2300, 18);

    int i;
    for(i=4; i<10; i++)
        managers[i] = NULL;
}
void initializeCustomer(Customer *customers[10]){
    customers[0] = new Customer("Emma", "emma@gmail.com", "23-3-1994", 12345678, "female", "402-D block, 11P street, new york, usa", "2256011");
    customers[1] = new Customer("watson", "watson@gmail.com", "23-3-1994", 12345678, "female", "402-D block, 11P street, new york, usa", "2256012");
    customers[2] = new Customer("elizebeth", "elizebeth@gmail.com", "23-3-1994", 12345678, "female", "402-D block, 11P street, new york, usa", "2256013");
    customers[3] = new Customer("olsen", "olsen@gmail.com", "23-3-1994", 12345678, "female", "402-D block, 11P street, new york, usa", "2256014");

    int i;
    for(i=4; i<10; i++)
        customers[i] = NULL;
}

template <typename T>
void printArray(T *arr[10]){
    int i;
    for(i=0; i<10; i++){
        if(arr[i] != NULL)
            arr[i]->print();
    }
}

int main()
{
    Employee *employees[10];
    Product *products[10];
    Manager *managers[10];
    Customer *customers[10];

    initializeProducts(products);
    initializeEmployees(employees);
    initializeManagers(managers);
    initializeCustomer(customers);


    cout << "=============== Initial employee list ===============" << endl;
    printArray(employees);

    cout << "\n\n=============== Initial products list ===============" << endl;
    printArray(products);

    cout << "\n\n=============== Initial customers list ===============" << endl;
    printArray(customers);

    cout << "\n\n**************** Manager \"Diesel\", increasing salary of EMPLOYEE by 10% ****************" << endl;
    cout << "Employee detail BEFORE increment: " << endl;
    employees[4]->print();
    managers[1]->increaseEmployeeSalary(employees, "cruise", "123-324", 10);
    cout << "Employee detail AFTER increment: " << endl;
    employees[4]->print();


    cout << "\n\n\n**************** Manager \"Brad\", increasing salary of SALES MAN (successful sales: 3 ) ****************" << endl;
    cout << "Sales man detail BEFORE increment: " << endl;
    employees[1]->print();
    managers[2]->increaseEmployeeSalary(employees, "jessica", "123-3222", 0);
    cout << "Sales man detail AFTER increment: " << endl;
    employees[1]->print();

    cout << "\n\n\n**************** Manager \"win\", increasing salary of SALES MAN (successful sales: 7 ) ****************" << endl;
    cout << "Sales man detail BEFORE increment: " << endl;
    employees[1]->print();
    managers[0]->increaseEmployeeSalary(employees, "statham", "123-322", 0);
    cout << "Sales man detail AFTER increment: " << endl;
    employees[1]->print();

    cout << "\n\n\n**************** Manager \"Pitt\", increasing salary of SALES MAN (successful sales: 12 ) ****************" << endl;
    cout << "Sales man detail BEFORE increment: " << endl;
    employees[0]->print();
    managers[3]->increaseEmployeeSalary(employees, "jason", "123-321", 0);
    cout << "Sales man detail AFTER increment: " << endl;
    employees[0]->print();

    return 0;
}
