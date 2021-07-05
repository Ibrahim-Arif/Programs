#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// class client, includes all information about a client.
class Client{
public:
    // id = client's ID
    // total sales = total number of sales with a specific client.
    // name = client's name
    // address = short address of client
    int id, totalSales;
    string name, address;

    //default constructor to make an object of client with no parameters.
    Client(){}
    //parameterized constructor for a object with full information
    Client(int i, int ts, string n, string a){
        id = i;
        totalSales = ts;
        name = n;
        address = a;
    }

    Client create(int i){
        int totalSales;
        string name, address;
        cout << "Enter info for new client." << endl;

        cout << "Enter name (avoid blank spaces): ";
        cin >> name;
        cout << "Enter address (avoid blank spaces): ";
        cin >> address;
        totalSales = 0;

        return Client(i, totalSales, name, address);
    }

    void update(){
        cout << "Enter updated info of client" << endl;

        cout << "Enter name (avoid blank spaces): ";
        cin >> name;
        cout << "Enter address (avoid blank spaces): ";
        cin >> address;
        cout << "Enter total sales: ";
        cin >> totalSales;
    }

    // print function will print all information about client.
    void print(){
        cout << endl;
        cout << "---------Client Info----------" <<endl;
        cout << "Name: "<< name <<endl;
        cout << "ID: "<< id <<endl;
        cout << "Address: "<< address <<endl;
        cout << "Total sales: " << totalSales <<endl;
    }
};
