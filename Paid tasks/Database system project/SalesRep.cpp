#include <fstream>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

// class SalesRep, includes all information about a sales representative.
class SalesRep{
public:
    // id = sales representative's ID
    // total sales = total number of sales done by a sales representative
    // name = sales representative's name
    // address = short address of sales representative
    int id, totalSales, totalSalesCost;
    string name, address;

    //default constructor to make an object of sales representative with no parameters.
    SalesRep(){}
    //parameterized constructor for a object with full information
    SalesRep(int i, int ts, int tsc, string n, string a){
        id = i;
        totalSales = ts;
        name = n;
        address = a;
        totalSalesCost= tsc;
    }

    SalesRep create(int i){
        int totalSales, totalSalesCost;
        string name, address;
        cout << "Enter info for new sales representative." << endl;

        cout << "Enter name (avoid blank spaces): ";
        cin >> name;
        cout << "Enter address (avoid blank spaces): ";
        cin >> address;

        totalSales = 0;
        totalSalesCost =0;

        return SalesRep(i, totalSales, totalSalesCost, name, address);
    }

    void update(){
        cout << "Enter updated info of sales representative." << endl;

        cout << "Enter name (avoid blank spaces): ";
        cin >> name;
        cout << "Enter address (avoid blank spaces): ";
        cin >> address;
        cout << "Enter total sales: ";
        cin >> totalSales;
        cout << "Enter total sales cost: ";
        cin >> totalSalesCost;
    }


    // print function will print all information about sales representative.
    void print(){
        cout << endl;
        cout << "---------Sales representative Info----------" <<endl;
        cout << "Name: "<< name <<endl;
        cout << "ID: "<< id <<endl;
        cout << "Address: "<< address <<endl;
        cout << "Total sales: " << totalSales <<endl;
        cout << "Total sales cost: " << totalSalesCost<<endl;
    }
};
