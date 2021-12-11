#include <iostream>
using namespace std;


class Node{
public:
	// ID of customer
    int id;
    
    // priority of customer which will decide customer's type.
    // VIP customer priority     = 1
	// Normal customer priority  = 2
    int priority;
    
    Node *left;
    Node *right;

    Node(){}
    Node(int d, int p){
        id = d;
        priority = p;
        left = NULL;
        right = NULL;
    }
};
class SmartQueue{
public:
    Node *rear, *front;
    SmartQueue(){
        rear = front = NULL;
    }

    void enqueue(int id, int prio){
        Node *n = new Node(id, prio);
        if(!rear){
            rear = front = n;
            return;
        }
        n->right = rear;
        rear->left = n;
        rear = n;

        adjust();
    }

    int dequeue(){
        int value;
        Node *temp = front;

        if(temp)
            value = temp->id;
        else
            return -1;

        if(front == rear){
            delete temp;
            front = rear = NULL;

            return value;
        }

        front = front->left;
        front->right = NULL;
        delete temp;

        return value;
    }

	// helper function to adjust elements in queue according to their priorities.
    void adjust(){
        Node *temp = rear, *next;
        int hold;

        while(temp){
            next = temp->right;
            if(!next)
                return;

            if(temp->priority < next->priority){
                hold = temp->id;
                temp->id = next->id;
                next->id = hold;

                hold = temp->priority;
                temp->priority = next->priority;
                next->priority = hold;
            }

            temp = temp->right;
        }
    }
    
    void clear(){
    	Node *temp = rear, *next;
    	
    	while(temp){
    		next = temp->right;
    		delete temp;
    		temp = next;
		}
		
		front = rear = NULL;
	}
	
	bool isEmpty(){
		return rear == NULL ? true : false;
	}
	
	int frontEl(){
		return front->id;
	}
};


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
    string address, cardNo, type;

    Customer() :Person(){}
    Customer(string name, string email, string DOB, int phoneNo, string gender, string address, string cardNo, string type) :Person(name, email, DOB, phoneNo, gender){
        this->address = address;
        this->cardNo = cardNo;
        this->type = type;
    }

    void print(){
        cout << "----- Customer -----" << endl;
        cout << "Name: " << name << endl;
        cout << "Type: " << type << endl;
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

int main()
{
	// VIP customer priority     = 1
	// Normal customer priority  = 2
	SmartQueue smart_queue;
	
	cout << "----- Inserting Normal priority customers in queue with ID = 1, 2 -----" << endl;
	smart_queue.enqueue(1, 2);
	smart_queue.enqueue(2, 2);
	cout << "Front element (customer ID): " << smart_queue.frontEl() << endl;
	
	cout << "\n----- Inserting VIP priority customer in queue with ID = 3 -----" << endl;
	smart_queue.enqueue(3, 1);
	cout << "Front element after VIP (customer ID): " << smart_queue.frontEl() << endl;
	
	cout << "\n----- Dequeuing front customer -----" << endl;
	cout << "Dequeued element (customer ID): " << smart_queue.dequeue() << endl;
	cout << "Front element after Dequeue (customer ID): " << smart_queue.frontEl() << endl;
	
	cout << "\n----- Dequeuing front customer AGAIN -----" << endl;
	cout << "Dequeued element (customer ID): " << smart_queue.dequeue() << endl;
	cout << "Front element after Dequeue AGAIN (customer ID): " << smart_queue.frontEl() << endl;
	
	cout << "\n----- Inserting VIP priority customer in queue with ID = 55 -----" << endl;
	smart_queue.enqueue(55, 1);
	cout << "Front element after VIP (customer ID): " << smart_queue.frontEl() << endl;
	
	cout << "\n----- Clearing the Queue -----" << endl;
	smart_queue.clear();
	cout << "Is queue empty: ";
	if(smart_queue.isEmpty())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	
    return 0;
}
