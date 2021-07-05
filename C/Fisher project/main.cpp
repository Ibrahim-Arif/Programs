#include <iostream>
#include<ctime>
using namespace std;


class Fish{
private:
    string name = "";
    double weight=0, purchasedCost=0, sellingPrice=0, balance=0;
    int units=0;
    char *expiry;

public:
    Fish(){
    }
    Fish(string n, double w, double pc, double b){
        name = n;
        weight = w;
        purchasedCost = pc;
        balance = b;

        Fish::setUnits(Fish::calculateUnits(n));
        Fish::setExpiry(Fish::calculateExpiry());
    }

       char* calculateExpiry(){
            time_t current_date = time(0);
            tm *inTime = gmtime(&current_date);

            inTime->tm_mday += 3;                  // adding 3 days in current date.

            if(inTime->tm_mday > 30){            // if total days exceed 30 then adjusting them by modulo by 30
                inTime->tm_mday %= 30;
                ++inTime->tm_mon;
            }
            return asctime(inTime);
       }
       int calculateUnits(string n){
           srand(time(NULL));

           if(n == "Cod")
                return rand() % 11+ 10;           // range (10 - 20)
           if(n == "Plaice")
                return rand() %  11+ 10;            // range (10 - 20)
           if(n == "Salmon")
                return rand() % 11+ 15;             // range (15 - 25)
           if(n == "Haddock")
                return rand() % 11 + 5;              // range (5 - 15)
           if(n == "Tuna")
                return rand() % 10 + 1;             // range (1 - 10)
       }

       void setExpiry(char *e){
           expiry = e;
       }
       void setName(string n){
           name = n;
       }
       void setUnits(int u){
           units = u;
       }
       void setWeight(double w){
           weight = w;
       }
       void setPurchasedCost(double pc){
           purchasedCost = pc;
       }
       void setBalance(double b){
           balance = b;
       }


       char* getExpire(){
           return expiry;
       }
       string getName(){
           return name;
        }
       double getWeight(){
           return weight;
        }
       double getPurchasedCost(){
           return purchasedCost;
        }
        double getSellingPrice(){
            if(name == "Cod" || name =="Plaice")
                return purchasedCost * 2;
            if(name == "Salmon" || name == "Haddock")
                return purchasedCost * 3;
           if(name == "Tuna")
                return purchasedCost * 4;
       }
       double getTSP(){                          // total purchased price
            if(name == "Cod" || name == "Plaice")
                return units * weight * purchasedCost * 2;
           if(name == "Salmon" || name == "Haddock")
                return units * weight * purchasedCost * 3;
           if(name == "Tuna")
                return units * weight * purchasedCost * 4;
       }
        double getTPC(){                     // total purchased cost
           return units * weight * purchasedCost;
        }
       double getTW(){                  // total weight
           return (double)units * weight;
        }
       int getUnits(){
           return units;
        }
       double getbalance(){
           return balance;
       }

       void isPurchased(int n){
           double amount = purchasedCost * weight * n;

           if(balance >= amount){
               units += n;
               balance -= amount;
           }
           else
               cout<<"ALERT! PURCHASING UNSUCCESSFUL"<<endl;
       }

       void sellingUnits(int n){
           if(units >= n){
               units -= n;
               int income, profit;

               if(name == "Cod" || name == "Plaice"){
                    income = purchasedCost * weight * n *2;
                    profit = purchasedCost*n*weight*1;
               }
               if(name == "Salmon" || name == "Haddock"){
                   income = purchasedCost * weight * n * 3;
                   profit = purchasedCost * n * weight * 2;
               }
               if(name == "Tuna"){
                   income = purchasedCost * n * weight * 4;
                   profit = purchasedCost * n * weight * 3;
               }

               cout<<"Name: "<< getName() <<", selling quantity: "<< n <<", total weight: "<< n*weight <<", selling price/kg: "<< purchasedCost <<", income: "<< income <<", profit: "<< profit <<endl<<endl;
           }
           else
               cout<<"ALERT! SELLING UNSUCCESSFUL"<<endl;
       }
};

class Shellfish : public Fish{
   public:
       Shellfish():Fish(){
       }
       Shellfish(string n, double w, double pc, double b) : Fish(n, w, pc, b){
           time_t current_date = time(0);
            tm *inTime = gmtime(&current_date);

            inTime->tm_mday += 2;                  // adding 2 days in current date.

            if(inTime->tm_mday > 30){            // if total days exceed 30 then adjusting them by modulo by 30
                inTime->tm_mday %= 30;
                ++inTime->tm_mon;
            }

            Fish::setExpiry(asctime(inTime));
            Fish::setUnits(calculateUnits(n));
       }

       int calculateUnits(string n){
           srand(time(NULL));

           if(n == "Mussel")
                return rand() % 161 + 40;          // range 40-200
           if(n == "Prawn")
                return rand() % 101 + 50;          // range 50-150
           if(n == "Scallop")
                return rand() % 81 + 20;          // range 20-100
       }

       void setUnits(string n){
           Fish::setUnits(calculateUnits(n));
       }

       double getSellingPrice(){
           if(getName() == "Mussel" || getName()=="Prawn")
                return getPurchasedCost() * 4;
           if(getName()=="Scallop")
                return getPurchasedCost() * 5;
       }
       double getTSP(){
           if(getName()=="Mussel" || getName()=="Prawn")
                return getUnits() * getWeight() * getPurchasedCost() *4;
           if(getName()=="Scallop")
                return getUnits() * getWeight() * getPurchasedCost() *5;
       }

       int totalPrawnPacket(){
           int p=0;
           if(getName() == "Prawn"){
               if(getUnits() % 30 != 0)
                   p = 1;
               p += (getUnits() / 30);
           }
           return p;
       }

       double priceOfPrawnPacket(){
           int p=0;
           if(getName() == "Prawn")
               p = getWeight() * getPurchasedCost() * 4 * 30;

           return p;
       }

       void sellingUnits(int num){
           if(getUnits() >= num){
               Fish::setUnits(getUnits() - num);

               string name = getName();
               double profit = 0, inc=0;

               if(name == "Mussel" || name == "Prawn"){
                    profit = getPurchasedCost() * getWeight() * num * 3;
                    inc = getPurchasedCost() * num * getWeight() * 4;
               }
               else if(name == "Scallop"){
                    profit = getPurchasedCost() * getWeight() * num * 4;
                    inc = getPurchasedCost() * num * getWeight() * 5;
               }

               Fish::setBalance(getbalance() + inc);

               if(name=="Cod" || name=="Plaice" || name=="Salmon" || name=="Haddock" || name=="Tuna")
                   cout<<"Fish name: "<<name<<endl;
               else
                   cout<<"Shellfish name: "<<name<<endl;

               cout<<"Quantity in units: "<<num<<"Total weight: "<<(num*getWeight())<<"Selling price/s: "<<(getPurchasedCost())<<"Income: "<<inc<<" Profit: "<<profit<<endl<<endl;
           }else
               cout<<"ALERT! SELLING UNSUCCESSFUL"<<endl;
       }
};

void initialize_fish(Fish *f){
    f[0] = Fish("Cod", 0.37, 6.5, 50);                      // n, w, pc, b
    f[1] = Fish("Plaice", 0.37, 5.25, 50);
    f[2] = Fish("Salmon", 1.3, 4.5, 50);
    f[3] = Fish("Haddock", 0.37, 4, 50);
    f[4] = Fish("Tuna", 0.45, 6.50, 50);
}

void initialize_shellfish(Shellfish *sf){
    sf[0] = Shellfish("Mussel", 0.05, 4, 50);
    sf[1] = Shellfish("Prawn", 0.02, 6.25, 50);
    sf[2] = Shellfish("Scallop", 0.03, 6.50, 50);
}

void printFish(Fish *f){
     for(int i=0;i<5;i++)
        cout<<f[i].getName()<<" : total weight is "<<f[i].getTW()<<" , total units "<<f[i].getUnits()<<" , balance = $"<<f[i].getbalance()<<endl;
    cout<<endl;
}

void printShellfish(Shellfish *sf){
    for(int i=0;i<3;i++)
        cout<<sf[i].getName()<<" : total weight is "<<sf[i].getTW()<<" , total units "<<sf[i].getUnits()<<" , balance = $"<<sf[i].getbalance()<<endl;
    cout<<endl;
}

int main()
{
    srand(time(NULL));

    Fish *f = new Fish[5];
    initialize_fish(f);

    Shellfish *sf = new Shellfish[3];
    initialize_shellfish(sf);

    cout<<"********* Fishes initial record *********"<<endl;
    printFish(f);

    int i = 2;
    cout<<"Fish \""<<f[i].getName()<<"\" purchased "<<3<<" units"<<endl;
    f[i].isPurchased(3);

    i = 0;
    cout<<"Fish v"<<f[i].getName()<<"\" purchased "<<8<<" units"<<endl;
    f[i].isPurchased(8);

    i = 4;
    cout<<"Fish \""<<f[i].getName()<<"\" purchased "<<11<<" units"<<endl;
    f[i].isPurchased(11);

    cout<<"\n\n********* Fish record after some purchases *********"<<endl;
    printFish(f);

    i = 3;
    cout<<"Fish \""<<f[i].getName()<<"\" selling "<<4<<" units"<<endl;
    f[i].sellingUnits(4);

    i = 1;
    cout<<"Fish \""<<f[i].getName()<<"\" selling "<<50<<" units"<<endl;
    f[i].sellingUnits(50);

    cout<<"\n\n********* Fish record after some selling *********"<<endl;
    printFish(f);

    cout<<"\n################################################## \n"<<endl;
    cout<<"********* Shell fishes initial record *********"<<endl;
    printShellfish(sf);

    i = 2;
    cout<<"Shell fishes \""<<sf[i].getName()<<"\" purchased "<<2<<" units"<<endl;
    sf[i].isPurchased(2);

    i = 0;
    cout<<"Shell fishes \""<<sf[i].getName()<<"\" purchased "<<5<<" units"<<endl;
    sf[i].isPurchased(5);


    cout<<"\n\n********* Shell fishes record after some purchases *********"<<endl;
    printShellfish(sf);

    i = 2;
    cout<<"Shell fishes \""<<sf[i].getName()<<"\" selling "<<2<<" units"<<endl;
    sf[i].sellingUnits(2);

    i = 1;
    cout<<"Shell fishes \""<<sf[i].getName()<<"\" selling "<<4<<" units"<<endl;
    sf[i].sellingUnits(4);

    cout<<"\n\n********* Fish record after some selling *********"<<endl;
    printShellfish(sf);

    cout<<"\nEnded"<<endl;
    return 0;
}
