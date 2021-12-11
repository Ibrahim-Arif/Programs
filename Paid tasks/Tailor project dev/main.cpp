#include <iostream>
#include <vector>
using namespace std;

class product{
private:
    string name, color;
    double price;

public:
    bool isShirt, isPant, isJacket;

    product(){
    	price = 0;
	}
    product(string n, string c, double p){
        name = n;
        color = c;
        price = p;
    }
    product(string n, string c, double p, bool is, bool ip, bool ij){
        name = n;
        color = c;
        price = p;
        isShirt = is;
        isPant = ip;
        isJacket = ij;
    }


    string getName(){
        return name;
    }
    void setName(string n){
        name = n;
    }
    string getColor(){
        return color;
    }
    void setColor(string c){
        color = c;
    }
    double getPrice(){
        return price;
    }
    void setPrice(double p){
        price = p;
    }

    virtual void print(){
        cout << "Name: " << name << endl;
        cout << "Color: " << color << endl;
        cout << "Price: " << price << endl;
        cout << endl;
    }
    void create_new(){
        cout << "Enter name: ";
        getline(cin, name);
        getline(cin, name);
        cout << "Enter color: ";
        cin >> color;
        cout << "Enter price: ";
        cin >> price;

        cout << "\n*** Enter 1 or 0 ***" << endl;
        cout << "Contain a Shirt? ";
        cin >> isShirt;
        cout << "Contain a Pant? ";
        cin >> isPant;
        cout << "Contain a Jacket? ";
        cin >> isJacket;
    }
};

class jacket: public product{
private:
    double neckSize, chestSize;

public:

    jacket(){
    	neckSize=0; 
		chestSize=0;
	}
    jacket(string n, string c, double p): product(n, c, p) {
    	neckSize=0; 
		chestSize=0;
	}
    jacket(string n, string c, double p, double ns, double cs): product(n, c, p) {
        neckSize = ns;
        chestSize = cs;
    }

    double getNeckSize(){
        return neckSize;
    }
    void setNeckSize(double siz){
        neckSize = siz;
    }
    double getChestSize(){
        return chestSize;
    }
    void setChestSize(double siz){
        chestSize = siz;
    }

    virtual void print(){
        cout << "Neck size, Chest size: " << neckSize << ", " << chestSize << endl;
    }
    void buyer(){
        cout << "Enter Chest size: ";
        cin >> chestSize;

        cout << "Enter neck size: ";
        cin >> neckSize;
    }
};

class pant: public product{
private:
    double waistLine, length;

public:
    pant(){
    	waistLine=0;
		length=0;
	}
    pant(string n, string c, double p): product(n, c, p) {
    	waistLine=0;
		length=0;
	}
    pant(string n, string c, double p, double wl, double l): product(n, c, p) {
        waistLine = wl;
        length = l;
    }

    double getWaistLine(){
        return waistLine;
    }
    void setWaistLine(double siz){
        waistLine = siz;
    }
    double getLength(){
        return length;
    }
    void setLength(double siz){
        length = siz;
    }

    virtual void print(){
        cout << "Waist line, Length: " << waistLine << ", " << length << endl;
    }
    void buyer(){
        cout << "Enter waist line: ";
        cin >> waistLine;

        cout << "Enter Pant length: ";
        cin >> length;
    }
};

class shirt: public product{
private:
    double neckSize, chestSize;

public:
    shirt(){
    	neckSize=0;
		chestSize=0;
	}
    shirt(string n, string c, double p): product(n, c, p){}
    shirt(string n, string c, double p, double ns, double cs): product(n, c, p) {
        neckSize = ns;
        chestSize = cs;
    }

    double getNeckSize(){
        return neckSize;
    }
    void setNeckSize(double siz){
        neckSize = siz;
    }
    double getChestSize(){
        return chestSize;
    }
    void setChestSize(double siz){
        chestSize = siz;
    }

    virtual void print(){
        cout << "Neck size, Chest size: " << neckSize << ", " << chestSize << endl;
    }
    void buyer(){
        cout << "Enter Chest size: ";
        cin >> chestSize;

        cout << "Enter neck size: ";
        cin >> neckSize;
    }
};

class dress: public product{
public:
    shirt shirt;
    pant pant;
    jacket jacket;

    dress(){}
    dress(string n, string c, double p, bool is, bool ip, bool ij): product(n, c, p, is, ip, ij){}

    virtual void print(){
        cout << "Name: " << getName() << endl;

        if(isShirt)
            shirt.print();
        if(isPant)
            pant.print();
        if(isJacket)
            jacket.print();

        cout << endl;
    }

    void customize(){
        if(isShirt)
            shirt.buyer();
        if(isPant)
            pant.buyer();
        if(isJacket)
            jacket.buyer();
    }

};


void setInitial(vector<product> &men_services, vector<product> &women_services){
    men_services.push_back(dress("three piece suit", "Royal blue", 5600, true, true, true));
    men_services.push_back(dress("two piece suit", "Sea green", 13500, true, true, true));
    men_services.push_back(dress("batik", "Red", 3500, true, true, false));
    men_services.push_back(dress("baju melayu", "White", 1000, true, true, false));
    men_services.push_back(dress("formal shirt", "pink", 1200, true, false, false));

    women_services.push_back(dress("baju kurung", "white & blue", 1300, true, true, true));
    women_services.push_back(dress("cheongsam", "green", 2500, true, true, false));
    women_services.push_back(dress("formal top", "black", 340, true, false, false));
}
void printList(vector<product> list){
    for(unsigned int i=0; i<list.size(); i++)
        list[i].print();
    cout << endl;
}

int main()
{
    int gender, choice = -1, ordersCount=0;
    vector<product> men_services;
    vector<product> women_services;
    vector<product> *temp;

    product **orders = new product*[50];

    setInitial(men_services, women_services);

    cout << "---------------- Initial Available Services for Men ----------------" << endl;
    printList(men_services);
    cout << "---------------- Initial Available Services for Women --------------" << endl;
    printList(women_services);
    cout << "--------------------------------------------------------------------" << endl;

    cout << "\n1: Men \n2: Women" << endl;
    cout << "\nPick an option: ";
    cin >> gender;

    switch(gender){
        case 1:{
            temp = &men_services;
            break;
        }
        case 2:{
            temp = &women_services;
            break;
        }
        default :{
            cout << "*** Error !! Wrong Input. ***" << endl;
            return 1;
        }
    }

    while(choice){
        cout << "\n1: Add service \n2: Delete service \n3: View All \n4: Purchase \n5: View Orders \n0: EXIT" << endl;
        cout << "\nPick an option: ";
        cin >> choice;

        switch(choice){
            case 1:{
                dress d;
                d.create_new();
                temp->push_back(d);
                cout << "\n*** New Service Added Successfully. ***" << endl;
                break;
            }
            case 2:{
                bool flag = false;
                string name;

                cout << "Enter service name: ";
                getline(cin, name);
                getline(cin, name);

				unsigned int i;
				for(i=0; i<temp->size(); i++){
					if(temp->at(i).getName() == name){
                        flag = true;
                        break;
                    }
				}
				
				temp->erase(temp->begin() +i);
				cout << "*** " << name << " service removed *** " << endl;
				
                if(!flag)
                    cout << "*** No service with name \'" << name << "\' found ***" << endl;

                break;
            }
            case 3:{
                cout << "---------------- Available Services ----------------" << endl;
                printList(*temp);
                break;
            }
            case 4:{
                bool flag = false;
                dress *d;
                string name;

                cout << "Enter service name to purchase: ";
                getline(cin, name);
                getline(cin, name);

                unsigned int i;
				for(i=0; i<temp->size(); i++){
					if(temp->at(i).getName() == name){
						d = new dress(temp->at(i).getName(), temp->at(i).getColor(), temp->at(i).getPrice(), temp->at(i).isShirt, temp->at(i).isPant, temp->at(i).isJacket);
                        flag = true;
                    }
				}

                if(!flag){
                    cout << "*** No service with name \'" << name << "\' found ***" << endl;
                    break;
                }

                d->customize();
                orders[ordersCount++] = d;

                cout << endl << "*** " << name << " purchased successfully.. ***\n" << endl;
                break;
            }
            case 5:{
                if(!ordersCount){
                    cout << "*** No Orders to display ***\n" << endl;
                    break;
                }

                cout << "----------- Current Orders ------------" << endl;
                for(int i=0; i<ordersCount; i++)
                    orders[i]->print();
                break;
            }
            case 0:{
                break;
            }
            default :{
                cout << "Error !! Wrong Input. " << endl;
                break;
            }
        }
    }

    cout << "\n*** Goodbye... ***" << endl;
    return 0;
}

