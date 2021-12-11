#include <fstream>
#include <ctime>
#include <iostream>
#include <vector>

#include "Client.cpp"
#include "Product.cpp"
#include "Sale.cpp"
#include "SalesRep.cpp"

using namespace std;

// function to get current year. e.g: 2021, 2020 etc.
int getCurrentYear(){
    time_t tt = time(NULL);
    tm* ptr = localtime(&tt);
    return (ptr->tm_year)+1900;     // tm_year give year since 1900 so adding 1900 into it will make it right format
}
// function to get current month. e.g: 6, 12 etc.
int getCurrentMonth(){
    time_t tt = time(NULL);
    tm* ptr = localtime(&tt);
    return (ptr->tm_mon)+1;     // tm_mon give month from 0 to 11 so adding 1 into it will make it right format
}

// write client file
void writeClient(vector<Client> v){
    const char *filename = "clients.dat";
    remove(filename);
    ofstream file;
    file.open(filename);

    if(!file){
        cout << filename << " write request failed !!"<< endl;
        return;
    }

    file << v.size() << endl;
    for(unsigned int i=0; i<v.size(); i++){
        file << v[i].id << " ";
        file << v[i].name << " ";
        file << v[i].address << " ";
        file << v[i].totalSales << endl;
    }

    cout << filename<< " file write successfully." << endl;
    file.close();
}
// read client file
vector<Client> readClient(){
    vector<Client> v;
    const char *filename = "clients.dat";
    int size, id, totalSales;
    string name, address;


    ifstream file;
    file.open(filename);

    if(!file){
        cout << filename << " read request failed !!"<< endl;
        exit(1);
    }

    file >> size;
    for(int i=0; i<size; i++){
        file >> id;
        file >> name;
        file >> address;
        file >> totalSales;

        v.push_back(Client(id, totalSales, name, address));
    }

    cout << filename << " file read successfully." << endl;
    file.close();
    return v;
}

// write sales representative file
void writeSalesRep(vector<SalesRep> v){
    const char * filename = "salesRep.dat";
    remove(filename);
    ofstream file;
    file.open(filename);

    if(!file){
        cout << filename << " write request failed !!"<< endl;
        exit(1);
    }

    file << v.size() << endl;
    for(unsigned int i=0; i<v.size(); i++){
        file << v[i].id << " ";
        file << v[i].name << " ";
        file << v[i].address << " ";
        file << v[i].totalSales << " ";
        file << v[i].totalSalesCost << " " << endl;
    }

    cout << filename<< " file write successfully." << endl;
    file.close();
}
// read sales representative file
vector<SalesRep> readSalesRep(){
    vector<SalesRep> v;
    const char *filename = "salesRep.dat";
    int size, id, totalSales, totalSalesCost;
    string name, address;


    ifstream file;
    file.open(filename);

    if(!file){
        cout << filename << " read request failed !!"<< endl;
        exit(1);
    }

    file >> size;
    for(int i=0; i<size; i++){
        file >> id;
        file >> name;
        file >> address;
        file >> totalSales;
        file >> totalSalesCost;

        v.push_back(SalesRep(id, totalSales, totalSalesCost, name, address));
    }

    cout << filename << " file read successfully." << endl;
    file.close();
    return v;
}

// write product file
void writeProduct(vector<Product> v){
    const char * filename = "products.dat";
    remove(filename);
    ofstream file;
    file.open(filename);

    if(!file){
        cout << filename << " write request failed !!"<< endl;
        exit(1);
    }

    file << v.size() << endl;
    for(unsigned int i=0; i<v.size(); i++){
        file << v[i].id << " ";
        file << v[i].name << " ";
        file << v[i].price << " ";
        file << v[i].inStock << " " << endl;
    }

    cout << filename<< " file write successfully." << endl;
    file.close();
}
// read product file
vector<Product> readProduct(){
    vector<Product> v;
    const char *filename = "products.dat";
    int size, id, price, inStock;
    string name;


    ifstream file;
    file.open(filename);

    if(!file){
        cout << filename << " read request failed !!"<< endl;
        exit(1);
    }

    file >> size;
    for(int i=0; i<size; i++){
        file >> id;
        file >> name;
        file >> price;
        file >> inStock;

        v.push_back(Product(id, price, inStock, name));
    }

    cout << filename << " file read successfully." << endl;
    file.close();
    return v;
}

// write sales file
void writeSales(vector<Sale> v){
    const char * filename = "sales.dat";
    remove(filename);
    ofstream file;
    file.open(filename);

    if(!file){
        cout << filename << " write request failed !!"<< endl;
        exit(1);
    }

    file << v.size() << endl;
    for(unsigned int i=0; i<v.size(); i++){
        file << v[i].id << " ";
        file << v[i].clientID << " ";
        file << v[i].salesRepID << " ";
        file << v[i].productID << " ";
        file << v[i].amount << " ";
        file << v[i].month << " ";
        file << v[i].year << " " << endl;
    }

    cout << filename<< " file write successfully." << endl;
    file.close();
}
// read sales file
vector<Sale> readSale(){
    vector<Sale> v;
    const char *filename = "sales.dat";
    int size, id, clientID, salesRepID , productID, amount, year, month;

    ifstream file;
    file.open(filename);

    if(!file){
        cout << filename << " read request failed !!"<< endl;
        exit(1);
    }

    file >> size;
    for(int i=0; i<size; i++){
        file >> id;
        file >> clientID;
        file >> salesRepID;
        file >> productID;
        file >> amount;
        file >> month;
        file >> year;

        v.push_back(Sale(id, clientID, salesRepID, productID, amount, month, year));
    }

    cout << filename << " file read successfully." << endl;
    file.close();
    return v;
}

// print a generic vector, which it will take as a parameter.
template<typename T>
void printVector(vector<T> v){
    for(unsigned int i=0; i<v.size(); i++)
        v[i].print();
}

// search any object from generic vector
template<typename T>
void search(string name, vector<T> v){
    int flag = 0;
    for(unsigned int i=0; i<v.size(); i++){
        if(name == v[i].name){
            v[i].print();
            flag = 1;
        }
    }
    if(!flag)
        cout << name << " not found !!" << endl;
}

// it will update specific object from generic vector with the object it takes as a parameter.
template<typename T>
void update(string name, vector<T> &v){
    for(unsigned int i=0; i<v.size(); i++){
        if(name == v[i].name){
            v[i].update();
            cout << name <<  " updated successfully." << endl;
        }
    }
}

// writing initial data into file for using it in testing
void writeInitialData(){
    cout << "Writing Initial data" << endl;
    const char *clientfile = "clients.dat";
    const char *salefile = "sales.dat";
    const char *productfile = "products.dat";
    const char *salerepfile = "salesRep.dat";

    ifstream fileclient;
    fileclient.open(clientfile);

    ifstream filesalerep;
    filesalerep.open(salerepfile);

    ifstream fileproduct;
    fileproduct.open(productfile);

    ifstream filesale;
    filesale.open(salefile);

    if(!fileclient){
        vector<Client> initialClients;
        initialClients.push_back(Client(1, 5, "client1", "address1"));
        initialClients.push_back(Client(2, 7, "client2", "address2"));
        initialClients.push_back(Client(3, 2, "client3", "address3"));
        initialClients.push_back(Client(4, 11, "client4", "address4"));
        writeClient(initialClients);
    }

    if(!filesalerep){
        vector<SalesRep> initialSalesRep;
        initialSalesRep.push_back(SalesRep(1, 56, 76000, "saleperson1", "address1"));
        initialSalesRep.push_back(SalesRep(2, 33, 32000, "saleperson2", "address2"));
        initialSalesRep.push_back(SalesRep(3, 12, 90000, "saleerson3", "address3"));
        initialSalesRep.push_back(SalesRep(4, 45, 4000, "saleperson4", "address4"));
        writeSalesRep(initialSalesRep);
    }

    if(!fileproduct){
        vector<Product> initialProducts;
        initialProducts.push_back(Product(1, 4550000, true, "car1"));
        initialProducts.push_back(Product(2, 460000, false, "car2"));
        initialProducts.push_back(Product(3, 7078000, false, "car3"));
        initialProducts.push_back(Product(4, 3356000, true, "car4"));
        writeProduct(initialProducts);
    }

    if(!filesale){
        vector<Sale> initialSales;
        initialSales.push_back(Sale(1, 2, 3, 2, 23000, 5, 2014));
        initialSales.push_back(Sale(2, 1, 2, 3, 210000, 8, 2015));
        initialSales.push_back(Sale(3, 1, 2, 4, 50000, 1, 2011));
        initialSales.push_back(Sale(4, 2, 2, 4, 450000, 12, 2011));
        initialSales.push_back(Sale(5, 3, 4, 3, 1220050, 3,2017));
        initialSales.push_back(Sale(6, 4, 3, 3, 11000, 4, 2021));
        initialSales.push_back(Sale(7, 3, 1, 1, 24500, 4, 2021));
        writeSales(initialSales);
    }
    cout << endl;
}


void mainImp(){
    string input;
    int choice;
    vector<Client> clients;         // vectors to store clients data read from clients.dat file
    vector<SalesRep> salesRep;      // vectors to store sales representative data read from saleRep.dat file
    vector<Sale> sales;             // vectors to store sales data read from sales.dat file
    vector<Product> products;       // vectors to store products data read from products.dat file

    writeInitialData();             // writing initial data into files for using it in testing

    cout << "1: Client \n2: Sales Representative \n3: Product \n4: Sales " << endl;
    cout << "Please select a module: ";
    cin >> choice;


    switch(choice){
        case 1:{
            cout << "================ Client Section ================" << endl;
            clients = readClient();         // reading client files and storing into client vector

            cout << "\n1: Read file \n2: List All. \n3: Search \n4: Add \n5: Update \n6: Save \n0: EXIT" << endl;
            while(choice){
                cout << "\nEnter your choice: ";
                cin >> choice;

                switch(choice){
                    case 1:{
                        clients = readClient();         // reading client files and storing into client vector
                        break;
                    }
                    case 2:{
                        cout << "Records of client." << endl;
                        printVector(clients);
                        cout << endl;
                        break;
                    }
                    case 3:{
                        cout << "Enter client name to search: ";
                        cin >> input;
                        cout << "Searching " << input << endl;
                        search(input, clients);
                        cout << endl;
                        break;
                    }
                    case 4:{
                        Client temp = temp.create(clients.size()+1);
                        cout << "Adding a new client" << endl;
                        clients.push_back(temp);
                        cout << temp.name << " added successfully."<<endl;
                        cout << endl;
                        break;
                    }
                    case 5:{
                        cout << "Enter client name to update: ";
                        cin >> input;
                        update(input, clients);
                        cout << endl;
                        break;
                    }
                    case 6:{
                        cout << "Updating clients data file" << endl;
                        writeClient(clients);
                        cout << endl;
                        break;
                    }
                    case 0:{
                        break;
                    }
                    default :{
                        cout << "Wrong choice !!" <<endl;
                        break;
                    }
                }
            }
            break;
        }
        case 2:{
            cout << "================ Sales Representative Section ================" << endl;
            salesRep = readSalesRep();      // reading sales representative files and storing into salesRep vector

            cout << "\n1: Read file \n2: List All. \n3: Search \n4: Add \n5: Update \n6: Sales Bonus \n7: Save \n0: EXIT" << endl;
            while(choice){
                cout << "\nEnter your choice: ";
                cin >> choice;

                switch(choice){
                    case 1:{
                        salesRep = readSalesRep();      // reading sales representative files and storing into salesRep vector
                        break;
                    }
                    case 2:{
                        cout << "Records of sale persons." << endl;
                        printVector(salesRep);
                        cout << endl;
                        break;
                    }
                    case 3:{
                        cout << "Enter sales representative name to search: ";
                        cin >> input;
                        cout << "Searching " << input << endl;
                        search(input, salesRep);
                        cout << endl;
                        break;
                    }
                    case 4:{
                        SalesRep temp = temp.create(salesRep.size()+1);
                        cout << "Adding a new sales representative" << endl;
                        salesRep.push_back(temp);
                        cout << temp.name << " added successfully."<<endl;
                        cout << endl;
                        break;
                    }
                    case 5:{
                        cout << "Enter sales representative name to update: ";
                        cin >> input;
                        update(input, salesRep);
                        cout << endl;
                        break;
                    }
                    case 6:{
                        cout << "Calculating Sales Bonus" << endl;
                        for(unsigned int i=0; i<salesRep.size(); i++){
                            int total=0;
                            for(unsigned int j=0; j<sales.size(); j++){
                                if(salesRep[i].id == sales[j].salesRepID && sales[j].year == getCurrentYear())
                                    total += sales[j].amount;
                            }
                            cout << salesRep[i].name << " total sales in " << getCurrentYear() << "= " << total << endl;
                            cout << salesRep[i].name << " bonus(10%) = " <<total * 0.1 << endl << endl;
                        }
                        cout << endl;
                        break;
                    }
                    case 7:{
                        cout << "Updating sales Representative data file" << endl;
                        writeSalesRep(salesRep);
                        cout << endl;
                        break;
                    }
                    case 0:{
                        break;
                    }
                    default :{
                        cout << "Wrong choice !!" <<endl;
                        break;
                    }
                }
            }
            break;
        }
        case 3:{
            cout << "================ Product/Service Section ================" << endl;
            products = readProduct();       // reading products files and storing into products vector

            cout << "\n1: Read file \n2: List All. \n3: Search \n4: Add \n5: Update \n6: Monthly sales report \n7: Save \n0: EXIT" << endl;
            while(choice){
                cout << "\nEnter your choice: ";
                cin >> choice;

                switch(choice){
                    case 1:{
                        products = readProduct();       // reading products files and storing into products vector
                        break;
                    }
                    case 2:{
                        cout << "Records of Products." << endl;
                        printVector(products);
                        cout << endl;
                        break;
                    }
                    case 3:{
                        cout << "Enter product name to search: ";
                        cin >> input;
                        cout << "Searching " << input << endl;
                        search(input, products);
                        cout << endl;
                        break;
                    }
                    case 4:{
                        Product temp = temp.create(products.size()+1);
                        cout << "Adding a new product" << endl;
                        products.push_back(temp);
                        cout << temp.name << " added successfully."<<endl;
                        cout << endl;
                        break;
                    }
                    case 5:{
                        cout << "Enter product name to update: ";
                        cin >> input;
                        update(input, products);
                        cout << endl;
                        break;
                    }
                    case 6:{
                        cout << "Producing a Monthly Sales Report" << endl;
                        cout << "In month: " << getCurrentMonth() << endl;
                        for(unsigned int i=0; i<products.size(); i++){
                            int total=0, count=0;
                            for(unsigned int j=0; j<sales.size(); j++){
                                if(products[i].id == sales[j].productID && sales[j].month == getCurrentMonth()){
                                    total += sales[j].amount;
                                    count++;
                                }
                            }
                            cout << products[i].name << " total sold cost: " << total << " total sold number: " << count << endl;
                        }
                        cout << endl;
                        break;
                    }
                    case 7:{
                        cout << "Updating product data file" << endl;
                        writeProduct(products);
                        cout << endl;
                        break;
                    }
                    case 0:{
                        break;
                    }
                    default :{
                        cout << "Wrong choice !!" <<endl;
                        break;
                    }
                }
            }
            break;
        }
        case 4:{
            cout << "================ Sales Section ================" << endl;
            sales = readSale();             // reading sales files and storing into sales vector

            cout << "\n1: Read file \n2: New purchase. \n3: List all sales of current year \n4: Sales of specific client \n5: Update \n6: Save \n0: EXIT" << endl;
            while(choice){
                cout << "\nEnter your choice: ";
                cin >> choice;

                switch(choice){
                    case 1:{
                        sales = readSale();             // reading sales files and storing into sales vector
                        break;
                    }
                    case 2:{
                        Sale temp = temp.create(sales.size()+1);
                        sales.push_back(temp);
                        cout << "New sale added successfully." << endl;
                        cout << endl;
                        break;
                    }
                    case 3:{
                        cout << "Sales record from "<< getCurrentYear() << endl;
                        for(unsigned int i=0; i<sales.size(); i++){
                            if(sales[i].year == getCurrentYear())
                                sales[i].print();
                        }
                        cout << endl;
                        break;
                    }
                    case 4:{
                        int id;
                        cout << "Enter client ID: ";
                        cin >> id;
                        for(unsigned int i=0; i<sales.size(); i++){
                            if(sales[i].year == getCurrentYear() && sales[i].clientID == id)
                                sales[i].print();
                        }
                        cout << endl;
                        break;
                    }
                    case 5:{
                        int id;
                        cout << "Enter sale ID:";
                        cin >> id;
                        for(unsigned int i=0; i<sales.size(); i++){
                            if(sales[i].id == id)
                                sales[i].update();
                        }
                        cout << id << " updates successfully. "<<endl;
                        cout << endl;
                        break;
                    }
                    case 6:{
                        cout << "Updating sales data file" << endl;
                        writeSales(sales);
                        cout << endl;
                        break;
                    }
                    case 0:{
                        break;
                    }
                    default :{
                        cout << "Wrong choice !!" <<endl;
                        break;
                    }
                }
            }
            break;
        }
        default :{
            cout << "Wrong Input !!" << endl;
            break;
        }
    }

    writeClient(clients);
    writeProduct(products);
    writeSales(sales);
    writeSalesRep(salesRep);
    return;
}
