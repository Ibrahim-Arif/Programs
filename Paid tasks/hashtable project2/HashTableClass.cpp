/*
 * HashTableClass.cpp
 *
 * Author: Samuel Mandada
 */



#include "hashTable.h"

    HashTable::HashTable(){}

    int HashTable::hashIt(Date obj){
        int day = obj.day;
        int month = obj.month;
        int year = obj.year;
        int weekDayNum, weekCharInt;
        string weekDay;
        int binary[32] = {0};

        // NOTE!! instead of year^3 I'm taking year^2 because year^3 will exceeding the limit of long int or long long int
        long int key = (year*year) + (month*month) + day;
        toBinary(key, binary);        // getting binary of key 32-bits

        std::tm date_obj = { 0, 0, 0, day, month-1, year-1900 };
        std::time_t date_temp = std::mktime(&date_obj);
        const std::tm * date_out = std::localtime(&date_temp);
        weekDayNum = date_out->tm_wday;     // number of day of the week

        switch(weekDayNum){                 // using day of week number getting name of day
            case 0:{
                weekDay = "Sunday";
                break;
            }
            case 1:{
                weekDay = "Monday";
                break;
            }
            case 2:{
                weekDay = "Tuesday";
                break;
            }
            case 3:{
                weekDay = "Wednesday";
                break;
            }
            case 4:{
                weekDay = "Thursday";
                break;
            }
            case 5:{
                weekDay = "Friday";
                break;
            }
            case 6:{
                weekDay = "Saturday";
                break;
            }
        }

        int i = weekDay.length()-1;
        while(true){
            if(i < 0)
                break;

            int temp[32] = {0};
            for(int i=0; i<5; i++)          // getting the 5 low-order bits of key and Shifting these bits to the five high order bits
                temp[i] = binary[i+27];

            for(int i=31; i>4; i--)         // Shift the key’s 5 bits toward the right, make the 5 high order bits all zero
                binary[i] = binary[i-5];

            for(int i=0; i<5; i++)
                binary[i] = temp[i];        //  bitwise OR of temp with key

            key = toDecimal(binary);        // key binary to decimal
            weekCharInt = weekDay[i];       // character int of week from end to start
            key = key ^ weekCharInt;        // XOR key with character of week
            i--;
        }
        return key % length_of_vector;
    }

    void HashTable::read(){
        const char *filename = "data.dat";
        ifstream file;
        file.open(filename);
        string name, code;
        int day, month, year;
        int key, cost, seat;


        if(!file){
            cout << filename << " read request failed !!"<< endl;
            exit(1);
        }

        while(!file.eof()){
            file >> name;
            file >> day;
            file >> month;
            file >> year;
            file >> cost;
            file >> code;
            file >> seat;

            Theater temp(day, month, year, cost, seat, code, name );

            key = hashIt(temp.date);
            table[key].push_back(temp);
        }
        table[key].pop_back();              // last object of file gets read twice. so removing it.
        file.close();

        cout << "File read successfully !!" << endl;
    }
    void HashTable::write(){
        const char * filename = "data.dat";
        remove(filename);
        ofstream file;
        file.open(filename);

        if(!file){
            cout << filename << " write request failed !!"<< endl;
            exit(1);
        }

        for(int i=0; i<length_of_vector; i++)
            for(unsigned int j=0; j < table[i].size(); j++){
                table[i][j].toFile();
        }
        file.close();
        cout << "File write successfully !!" << endl;
    }

    void HashTable::insert() {
        string name, code;
        int seat, cost;
        Date date;

        cout << "Enter name: ";
        cin >> name;
        cout << "Enter code: ";
        cin >> code;
        cout << "Enter cost: ";
        cin >> cost;
        cout << "Enter seat: ";
        cin >> seat;

        date.create();
        Theater temp(date, cost, seat, code, name);

        int key = hashIt(temp.date);
        table[key].push_back(temp);
        cout << name << " inserted successfully !!" << endl << endl;
    }
    void HashTable::find(Date obj){
        int key = hashIt(obj);
        bool flag = false;

        for(unsigned int i=0; i<table[key].size(); i++){
            if(table[key][i].isMyDate(obj)){
                cout << table[key][i].toString() << endl;
                flag = true;
            }
        }
        if(!flag)
            cout << "\nNo object found with date: " << obj.toString() << endl;
    }
    void HashTable::printAll(){
        cout << "Username \tDate" <<endl;
        cout << "-------------------------" << endl;
        for(int i=0; i<length_of_vector; i++){
            for(unsigned int j=0; j<table[i].size(); j++)
                cout << table[i][j].toString() << endl;
        }
    }

    void HashTable::toBinary(long int num, int *binary){
        int i=31;
        while(num>0){
            binary[i--] = num%2;
            num /= 2;
        }
    }
    int HashTable::toDecimal(int binary[32]){
        int decimal=0, i=0, j=31, rem;
        while (j){
            rem = binary[j--];
            decimal += rem * pow(2, i++);
        }
        return decimal;
    }
