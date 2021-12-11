#include <iostream>
#include <fstream>
using namespace std;

struct GeneralStore{
    int product_id;
    string product_name;
    int quantity;
    double price;
    double discount;
};

void insert(){
    GeneralStore gs[10];

    gs[0] = {1, "chips", 10, 60, 5};
    gs[1] = {2, "lays", 5, 90, 2};
    gs[2] = {3, "wavy", 2, 55, 51};
    gs[3] = {4, "chocolate", 102, 78, 55};
    gs[4] = {5, "fock", 101, 601, 35};

    gs[5] = {6, "mango", 1022, 6, 15};
    gs[6] = {7, "banaan", 102, 20, 85};
    gs[7] = {8, "apple", 102, 60, 8};
    gs[8] = {9, "laptop", 103, 5000, 2};
    gs[9] = {10, "flowers", 104, 610, 1};

    ofstream MyFile("store.txt");

    for(int i=0; i<10; i++){
        MyFile << gs[i].product_name+" " ;
        MyFile << gs[i].product_id;
        MyFile <<" ";
        MyFile << gs[i].quantity;
        MyFile <<" ";
        MyFile << gs[i].price;
        MyFile <<" ";
        MyFile << gs[i].discount;
        MyFile <<"\n";
    }

  MyFile.close();
}

void display(){
    ifstream file("store.txt");
    string line;
    while (getline (file, line)) {
        if(line[0] == 'f')
            cout<<line<<endl;
        else
            cout<<"product not found"<<endl;
    }
    file.close();
}


int main()
{
    cout<<"I I: insert() \nD: display() \nS: sumOfPrice() \nP: discountProducts() \n\n"<<endl;
    insert();
    display();

    return 0;
}
