#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

int getCurrentYear(){
    time_t tt = time(NULL);
    tm* ptr = localtime(&tt);
    return (ptr->tm_year)+1900;
}
int getCurrentMonth(){
    time_t tt = time(NULL);
    tm* ptr = localtime(&tt);
    return (ptr->tm_mon)+1;
}

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
    }    // print function will print all information about Product.
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

    void setMonth(){
        month = getCurrentMonth();
    }
    void setYear(){
        year = getCurrentYear();
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
void update(string name, vector<T> &v, T obj){
    for(unsigned int i=0; i<v.size(); i++){
        if(name == v[i].name){
            v[i] = obj;
            cout << name <<  " updated successfully." << endl;
        }
    }
}

// writing initial data into file for using it in testing
void writeInitialData(){
    vector<Client> initialClients;
    initialClients.push_back(Client(1, 5, "Client-1", "Address-1"));
    initialClients.push_back(Client(2, 7, "Client-2", "Address-2"));
    initialClients.push_back(Client(3, 2, "Client-3", "Address-3"));
    initialClients.push_back(Client(4, 11, "Client-4", "Address-4"));
    writeClient(initialClients);

    vector<SalesRep> initialSalesRep;
    initialSalesRep.push_back(SalesRep(1, 56, 76000, "Sale-Person-1", "Address-1"));
    initialSalesRep.push_back(SalesRep(2, 33, 32000, "Sale-Person-2", "Address-2"));
    initialSalesRep.push_back(SalesRep(3, 12, 90000, "Sale-Person-3", "Address-3"));
    initialSalesRep.push_back(SalesRep(4, 45, 4000, "Sale-Person-4", "Address-4"));
    writeSalesRep(initialSalesRep);

    vector<Product> initialProducts;
    initialProducts.push_back(Product(1, 4550000, true, "Car-1"));
    initialProducts.push_back(Product(2, 460000, false, "Car-2"));
    initialProducts.push_back(Product(3, 7078000, false, "Car-3"));
    initialProducts.push_back(Product(4, 3356000, true, "Car-4"));
    writeProduct(initialProducts);

    vector<Sale> initialSales;
    initialSales.push_back(Sale(1, 2, 3, 2, 23000, 5, 2014));
    initialSales.push_back(Sale(2, 1, 2, 3, 210000, 8, 2015));
    initialSales.push_back(Sale(3, 1, 2, 4, 50000, 1, 2011));
    initialSales.push_back(Sale(4, 2, 2, 4, 450000, 12, 2011));
    initialSales.push_back(Sale(5, 3, 4, 3, 1220050, 3,2017));
    initialSales.push_back(Sale(6, 4, 3, 3, 11000, 4, 2021));
    initialSales.push_back(Sale(7, 3, 1, 1, 24500, 4, 2021));
    writeSales(initialSales);

    cout << endl;
}

int main()
{
    string input;
    vector<Client> clients;
    vector<SalesRep> salesRep;
    vector<Sale> sales;
    vector<Product> products;

    writeInitialData();

    clients = readClient();
    salesRep = readSalesRep();
    products = readProduct();
    sales = readSale();
    cout << endl;

    cout << "================ Client Section ================" << endl;
    cout << "Records of client." << endl;
    printVector(clients);
    cout << endl;

    cout << "Searching a client-1" << endl;
    search("Client-1", clients);
    cout << endl;

    cout << "Adding a new client" << endl;
    clients.push_back(Client(clients.size()+1, 0, "New-Client", "New-Address"));
    cout << "New Client added successfully."<<endl;
    cout << endl;

    cout << "Updating an existing client" << endl;
    update("Client-2", clients, Client(2, 22, "updated-client-2", "updated-address=2" ));
    cout << endl;

    cout << "Updating clients data file" << endl;
    writeClient(clients);
    cout << endl;

    cout << "================ Sales Representative Section ================" << endl;
    cout << "Records of sale persons." << endl;
    printVector(salesRep);
    cout << endl;

    cout << "Searching a sales representative-3" << endl;
    search("Sale-Person-3", salesRep);
    cout << endl;

    cout << "Adding a new sales person" << endl;
    salesRep.push_back(SalesRep(sales.size()+1, 0, 0, "New-sales-person", "new-address"));
    cout << "New sale person added successfully."<<endl;
    cout << endl;

    cout << "Updating an existing client" << endl;
    update("Sale-Person-2", salesRep, SalesRep(2, 11, 450000, "Updated-name-2", "Updated-address-2"));
    cout << endl;

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

    cout << "Updating sales representative data file" << endl;
    writeSalesRep(salesRep);
    cout << endl;

    cout << "================ Product/Service Section ================" << endl;
    cout << "Records of Products." << endl;
    printVector(products);
    cout << endl;

    cout << "Searching a product" << endl;
    search("Car-2", products);
    cout << endl;

    cout << "Adding a new product" << endl;
    products.push_back(Product(products.size()+1, 0, "New-Product", "New-Address"));
    cout << "New Product added successfully."<<endl;
    cout << endl;

    cout << "Updating an existing product" << endl;
    update("Car-2", products, Product(products.size()+1, 23000, true, "Updated-Car-name"));
    cout << endl;

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

    cout << "Updating product data file" << endl;
    writeProduct(products);
    cout << endl;

    cout << "================ Sales Section ================" << endl;
    cout << "Allow client to purchase a Product/Service" << endl;
    sales.push_back(Sale(sales.size()+1, 4, 2, 2, 100000, 4, 2021));
    cout << "New purchased added successfully." << endl;
    cout << endl;

    cout << "Sales record from "<< getCurrentYear() << endl;
    for(unsigned int i=0; i<sales.size(); i++){
        if(sales[i].year == getCurrentYear())
            sales[i].print();
    }
    cout << endl;

    cout << "Listing all sales for the year from a specific client" << endl;
    for(unsigned int i=0; i<sales.size(); i++){
        if(sales[i].year == getCurrentYear() && sales[i].clientID == 3)
            sales[i].print();
    }
    cout << endl;

    cout << "Updating information for a sale ID: 3." <<endl;
    for(unsigned int i=0; i<sales.size(); i++){
        if(sales[i].id == 3)
            sales[i] = Sale(3, 4, 2, 4, 1111110, 11, 2021);
    }
    cout << "Sale ID: 3 updates successfully. "<<endl;
    cout << endl;

    cout << "Updating sales data file" << endl;
    writeSales(sales);
    cout << endl;

    cout << endl;
    cout << "=============== Printing everything after all processing ================" << endl;
    cout << "Records of client." << endl;
    printVector(clients);
    cout << endl;

    cout << "Records of sale persons." << endl;
    printVector(salesRep);
    cout << endl;

    cout << "Records of Products." << endl;
    printVector(products);
    cout << endl;

    cout << "Records of sales." << endl;
    printVector(sales);
    cout << endl;

    return 0;
}
