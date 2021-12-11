#include <fstream>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

// class Product, includes all information about a Product.
class Product{
public:
    // id = Product's ID
    // name = Product's name
    // inStock = true if product is in stock and available for sale
    // price = Product's price
    int id, price;
    string name;
    bool inStock;

    //default constructor to make an object of Product with no parameters.
    Product(){}
    //parameterized constructor for a object with full information
    Product(int i, int p, bool is, string n){
        id = i;
        price = p;
        inStock = is;
        name = n;
    }

    Product create(int i){
        int price;
        string name;
        bool inStock;
        cout << "Enter info for new product." << endl;

        cout << "Enter name (avoid blank spaces): ";
        cin >> name;
        cout << "Enter price: ";
        cin >> price;

        inStock = true;

        return Product(i, price, inStock, name);
    }

    void update(){
        cout << "Enter updated info of product" << endl;

        cout << "Enter name (avoid blank spaces): ";
        cin >> name;
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter 1 if still available or 0: ";
        cin >> inStock;
    }

    // print function will print all information about Product.
    void print(){
        cout << endl;
        cout << "---------Product Info----------" <<endl;
        cout << "Name: "<< name <<endl;
        cout << "ID: "<< id <<endl;
        if(inStock)
            cout << "In stock status: Available "<<endl;
        else
            cout << "In stock status: Not Available "<<endl;
        cout << "Price: " << price <<endl;
    }
};
