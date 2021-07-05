#include <fstream>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

// function to get current year. e.g: 2021, 2020 etc.
int currentYear(){
    time_t tt = time(NULL);
    tm* ptr = localtime(&tt);
    return (ptr->tm_year)+1900;     // tm_year give year since 1900 so adding 1900 into it will make it right format
}
// function to get current month. e.g: 6, 12 etc.
int currentMonth(){
    time_t tt = time(NULL);
    tm* ptr = localtime(&tt);
    return (ptr->tm_mon)+1;     // tm_mon give month from 0 to 11 so adding 1 into it will make it right format
}

// class Sales, includes all information about a Sales.
class Sale{
public:
    // id = Sale's ID
    // clientID = id of client for a sale
    // salesRepID = id of sales representative for a sale
    // productID = id of product.
    // date = date of sale.
    // amount = amount of product sold
    int id, clientID, salesRepID, productID, amount, year, month;

    //default constructor to make an object of Sale with no parameters.
    Sale(){}
    //parameterized constructor for a object with full information
    Sale(int i, int cid, int spid, int pid, int a){
        id = i;
        amount = a;
        clientID = cid;
        salesRepID = spid;
        productID = pid;
        setMonth();
        setYear();
    }
    //parameterized constructor for a object with full information with MONTH
    Sale(int i, int cid, int spid, int pid, int a, int m, int y){
        id = i;
        amount = a;
        clientID = cid;
        salesRepID = spid;
        productID = pid;
        month = m;
        year = y;
    }

    // helper function to set month
    void setMonth(){
        month = currentMonth();
    }
    // helper function to set year
    void setYear(){
        year = currentYear();
    }

    Sale create(int i){
        int clientID, salesRepID, productID, amount, year, month;
        cout << "Enter info for new sale." << endl;

        cout << "Enter Product ID: ";
        cin >> productID;
        cout << "Enter Client ID: ";
        cin >> clientID;
        cout << "Enter Sales person ID: ";
        cin >> salesRepID;
        cout << "Enter amount: ";
        cin >> amount;
        cout << "Enter month (1-12): ";
        cin >> month;
        cout << "Enter year (e.g 2021): ";
        cin >> year;

        return Sale(i, clientID, salesRepID, productID, amount, month, year);
    }

    void update(){
        cout << "Enter updated info of sale" << endl;

        cout << "Enter Product ID: ";
        cin >> productID;
        cout << "Enter Client ID: ";
        cin >> clientID;
        cout << "Enter Sales person ID: ";
        cin >> salesRepID;
        cout << "Enter amount: ";
        cin >> amount;
        cout << "Enter month (1-12): ";
        cin >> month;
        cout << "Enter year (e.g 2021): ";
        cin >> year;
    }


    // print function will print all information about Sale.
    void print(){
        cout << endl;
        cout << "---------Sale Info----------" <<endl;
        cout << "ID: "<< id <<endl;
        cout << "Client ID: "<< clientID <<endl;
        cout << "Sale person ID: " << salesRepID <<endl;
        cout << "Product ID: " << productID << endl;
        cout << "Amount: " << amount << endl;
        cout << "(mm-yy): "<< month << "-" <<year <<endl;
    }
};
