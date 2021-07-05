#include <iostream>                                     // load factor should be < 75% or after 90% it will automatically resize table by 2x
#include <string>                                          // and try to use even number table size.
using namespace std;

template<class T>
class slot{
public:
    string key;
    T value;

    slot(){
        key = "";
    }
    slot(string k, T v){
        value = v;
        key = k;
    }
};

template<class T>
class double_hash{
public:
    slot<T> *table;
    int curr_size, table_size;
    double load_factor;

    double_hash(){}
    double_hash(int ts){
        table_size = ts;
        curr_size = 0;
        load_factor = 0;
        table = new slot<T>[table_size]{ slot<T>() };
    }

private:
    int hash1(string key){
        int hash = 0;

        for(int i=0; i<key.length(); i++)
            hash = (hash + int(key[i]) *i) % table_size;

        return hash;
    }
    int hash2(int hash_1){
        return ( 7 - (hash_1 % 7) );
    }

public:
    bool isFull(){
        return (curr_size == table_size);
    }
    void set(string key, T value){
        if(isFull()){
            cout<<"Hash table is overflow!"<<endl;
            return;
        }
        if(load_factor >= 0.90){
            re_size();
            cout<<endl<<"Alert! Table been resized."<<endl;
        }
        if(load_factor > 0.75){
            printf("\nWarning! load factor reached: %.2f \n",load_factor);
            cout<<"For continue insertion, press (y/n): ";
            string ch;
            cin >> ch;

            if(ch != "y")
                return;
        }
        int hash_1 = hash1(key);

        if(table[hash_1].key == "" || table[hash_1].key == "deleted"){
            table[hash_1] = slot<T>(key, value);
        }else{
            int hash_2 = hash2(hash_1), i=1;

            int new_hash = 0;
            while( true ){
                new_hash = (hash_1 + i * hash_2) % table_size;

                if(table[new_hash].key == "" || table[hash_1].key == "deleted"){
                    table[new_hash] = slot<T>(key, value);
                    break;
                }
                i++;
            }
        }
        curr_size++;
        load_factor = (double)curr_size / (double)table_size;
    }
    T get(string key){
        int i=1, new_index;
        int hash_1 = hash1(key);
        int hash_2 = hash2(hash_1);

        new_index = hash_1;

        while(table[new_index].key != key){
            if( table[new_index].key == "")
                return 0;
            i++;
            new_index = ( hash_1 + i * hash_2 ) %table_size;
        }
        return table[new_index].value;
    }
    void displayHash(){
        for(int i=0; i<table_size; i++){
            if( table[i].key != "" && table[i].key != "deleted")
                cout << i << " --> " << table[i].key << ": "<<table[i].value<<endl;
            else
                cout << i<<endl;
        }
    }
    void del(string key){
        int i=1, new_index;
        int hash_1 = hash1(key);
        int hash_2 = hash2(hash_1);

        new_index = hash_1;

        while(table[new_index].key != key){
            if( table[new_index].key == "")
                return;
            i++;
            new_index = ( hash_1 + i * hash_2 ) %table_size;
        }
        table[new_index].key = "deleted";
        table[new_index].value = 0;
        curr_size--;
        load_factor = (double) curr_size / (double) table_size;
    }
    void re_size(){
        double_hash<T> temp(table_size*2);

        for(int i=0; i<table_size; i++){
            if( table[i].key != "" && table[i].key != "deleted")
                temp.set(table[i].key, table[i].value);
        }
        table_size = temp.table_size;
        load_factor = temp.load_factor;
        table = temp.table;
    }
};

int main()
{
    double_hash<int> dh(50);                 // its better to make table of more than need because
                                                                  // while searching if no table is full then return 0 is not possible
    dh.set("grapes", 1);
    dh.set("apples", 2);

    dh.set("strawberry", 3);
    dh.set("banana", 4);

    dh.set("kela", 5);
    dh.set("orange", 6);

    dh.set("methay", 7);
    dh.set("phekay", 8);            // 8

/*
    cout<<dh.get("grapes")<<endl;
    cout<<dh.get("apples")<<endl;
    cout<<dh.get("strawberry")<<endl;
    cout<<dh.get("banana")<<endl;
    cout<<dh.get("kela")<<endl;
    cout<<dh.get("orange")<<endl;
    cout<<dh.get("methay")<<endl;
    cout<<dh.get("phekay")<<endl;
*/

    dh.displayHash();

    dh.set("HALWA", 60);
    dh.set("METHAI", 70);

    dh.set("BISCUITS", 80);     // 11

    cout<<endl;
    dh.displayHash();

    dh.set("PYTHON", 999);
    dh.set("C", 500);

    dh.set("C++", 70);
    dh.set("CSS", 81);          // 15

    dh.set("java", 500);
    dh.set("pithon", 70);

    dh.set("vision", 81);       // 18
    dh.set("ibrahim", 33);

    cout<<endl;
    dh.displayHash();

    return 0;
}
