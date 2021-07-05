#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class Employee
{
private:
    int id; 				// employee ID
    char name[25]; 			// employee name
    double hourlyPay; 		// pay per hour
    double numberOfHours; 	// total number of hours of an employee work in a week
    int numDeps; 			// number of dependents
    int type; 				// employee type

public:
    Employee( int initId=0, char initName[]=(char*)"", double initHourlyPay=0.0, int initNumDeps=0, int initType=0 ); // Constructor
    bool set(int newId, char newName[], double newHourlyPay, int newNumDeps, int newType);
    void setNumberOfHours(double noh);
    int getID();
    int getType();
    int getNumDeps();
    double getNumberOfHours();
    double getHourlyPay();
    char* getName();
};

    Employee::Employee( int initId, char initName[], double initHourlyPay, int initNumDeps, int initType ){
        bool status = set( initId, initName, initHourlyPay, initNumDeps, initType );
        if ( !status ){
            id = 0;
            memcpy(name, "", 1);
            hourlyPay = 0.0;
            numDeps = 0;
            type = 0;
        }
    }
    bool Employee::set( int newId, char newName[], double newHourlyPay, int newNumDeps, int newType){
        bool status = false;
         if(newId > 0 && newHourlyPay > 0 && newNumDeps >= 0 && newType >= 0 && newType <= 1){
             status = true;
             id = newId;
             memcpy(name, newName, 20);
             hourlyPay = newHourlyPay;
             numDeps = newNumDeps;
             type = newType;
         }
         return status;
    }
    void Employee::setNumberOfHours(double noh){
        numberOfHours = noh;
    }
    int Employee::getID(){
        return id;
    }
    int Employee::getType(){
        return type;
    }
    int Employee::getNumDeps(){
        return numDeps;
    }
    double Employee::getNumberOfHours(){
        return numberOfHours;
    }
    double Employee::getHourlyPay(){
        return hourlyPay;
    }
    char* Employee::getName(){
        return name;
    }

    int read_master_file(Employee (&employees)[100], char filename[]){
        int id, numDeps, type;
        double hourlyPay;
        char name[20], gender;

        ifstream masterFile(filename);

        if (!masterFile){
          cout << "!!! Can not open file \"" << filename << "\" file !!!" << endl;
          exit(0);
        }

        int i=0;
        while(!masterFile.eof()){
            masterFile >> id;
            masterFile.read(name, 20);
            masterFile >> hourlyPay;
            masterFile >> numDeps;
            masterFile >> type;
            masterFile >> gender;

            employees[i] = Employee(id, name, hourlyPay, numDeps, type);
            //cout << employees[i].getName() << endl;
            i++;
        }
        masterFile.close();
        cout << "--- \"" << filename << "\" read successfully ---" << endl;
        return i-1;
    }
    void read_transaction_file(Employee *employees, int totalEmployee, char filename[]){
        int id;
        double numberOfHours;

        ifstream transactionFile(filename);

        if (!transactionFile){
            cout << "!!! Can not open file \"" << filename << "\" file !!!" << endl;
            exit(0);
        }

        int i=0;
        while(!transactionFile.eof()){
            transactionFile >> id;
            transactionFile >> numberOfHours;

            for(int i=0; i<totalEmployee; i++){
                if(employees[i].getID() == id){
                    if(numberOfHours > 0)
                        employees[i].setNumberOfHours(numberOfHours);
                    else
                        employees[i].setNumberOfHours(0);
                }
            }
        }
        transactionFile.close();
        cout << "--- \"" << filename << "\" read successfully ---" << endl;
    }

    void error_and_control_report(Employee *employees, int totalEmployee, char filename[]){
        int choice = -1;
        int failedCount=0, passedCount=0;
        int id;
        double numberOfHours;


        cout << "\n1: Print error report to screen. \n2: Write error report to file. ";
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        ifstream transactionFile(filename);

        if (!transactionFile){
            cout << "!!! Can not open file \"trans10.txt\" !!!" << endl;
            return;
        }

        ofstream errorFile("errors_report.txt");
        if(choice == 2){
            if (!errorFile){
                cout << "!!! Can not create file \"errors_report.txt\" !!!" << endl;
                return;
            }
            errorFile << "------------ Report of all failed transactions ------------ \n\n";
        }
        else{
            cout << "------------ Report of all failed transactions ------------ " << endl;
        }

        int i=0;
        bool found;
        while(!transactionFile.eof()){
            transactionFile >> id;
            transactionFile >> numberOfHours;

            found = false;
            for(int i=0; i<totalEmployee; i++){
                if(employees[i].getID() == id){
                    if(numberOfHours > 0){
                        found = true;
                        passedCount++;
                    }
                }
            }

            if(!found){
                switch(choice){
                    case 1:{
                        cout << "ID: " << id << ", Hours: " << numberOfHours << endl;
                        break;
                    }
                    case 2:{
                        errorFile << "ID: " << id << ", Hours: " << numberOfHours << endl;
                        break;
                    }
                    default: {
                        cout << "Wrong Input !!!" << endl;
                        break;
                    }
                }
            }
        }

        if(choice == 1)
            cout << "\nTotal correctly processed transactions: " << passedCount << endl << endl;
        else if(choice == 2){
            errorFile << "\nTotal correctly processed transactions: " << passedCount << endl;
            cout << "--- errors_report.txt file write successfully ---" << endl;
        }

        errorFile.close();
        transactionFile.close();
    }
    void payroll_report(Employee *employees, int totalEmployee){
        double tax, insurance, gross_pay, net_pay;
        double totalGP=0, totalNP=0;
        int primaryGap=20, secondaryGap=13;

        ofstream payrollFile("payroll_report.txt");

        if (!payrollFile){
            cout << "!!! Can not create file \"payroll_report.txt\" !!!" << endl;
            return;
        }

        payrollFile << setw(2) << "ID"
                    << setw(primaryGap) << "Name            "
                    << setw(secondaryGap) << "Tax"
                    << setw(secondaryGap) << "Insurance"
                    << setw(secondaryGap) << "Gross Pay"
                    << setw(secondaryGap) << "Net Pay"
                    << endl;

        for(int i=0; i<totalEmployee; i++){
            tax = insurance = gross_pay = net_pay = 0;
            int total_hours = employees[i].getNumberOfHours();

            if(total_hours > 40 && employees[i].getType() == 0){        // union employee and over 40 hours work time
                int extra_hours = employees[i].getNumberOfHours() - 40;
                gross_pay += (extra_hours * (employees[i].getHourlyPay() * 1.5));

                total_hours -= extra_hours;
            }

            gross_pay += (total_hours * employees[i].getHourlyPay());
            tax = gross_pay * 0.15;
            insurance = employees[i].getNumDeps() * 30;
            net_pay = gross_pay - tax - insurance;

            //cout << employees[i].getName() << endl;

            payrollFile << setw(2) << employees[i].getID()
                        << setw(primaryGap) << employees[i].getName()
                        << fixed
                        << setprecision(2) << setw(secondaryGap) << tax
                        << setprecision(2) << setw(secondaryGap) << insurance
                        << setprecision(2) << setw(secondaryGap) << gross_pay
                        << setprecision(2) << setw(secondaryGap) << net_pay
                        << endl;

            totalGP += gross_pay;
            totalNP += net_pay;
        }

        payrollFile << "--------------------------------------------------------------------------- \n";
        payrollFile << fixed
                    << setw(48) << ""
                    << setprecision(2) << setw(secondaryGap) << totalGP
                    << setprecision(2) << setw(secondaryGap) << totalNP
                    << endl;

        payrollFile.close();
        cout << "--- payload_report.txt file generated successfully ---" << endl;
    }

//main function
int main()
{
    Employee employees[100];
    int totalEmployee;
    char    masterFileName[50] = "master.txt",
            transactionFileName[50] = "trans10.txt";


    totalEmployee = read_master_file(employees, masterFileName);
    read_transaction_file(employees, totalEmployee, transactionFileName);

    error_and_control_report(employees, totalEmployee, transactionFileName);
    payroll_report(employees, totalEmployee);

    return 0;
}
