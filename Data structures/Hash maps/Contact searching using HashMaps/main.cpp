#include <iostream>
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
            return;
        }
        if(load_factor >= 0.80){
            re_size();
        }
        int hash_1 = hash1(key);

        if(table[hash_1].key == "" || table[hash_1].key == key || table[hash_1].key == "deleted"){
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
    string que, ele;
    double_hash<int> dh(20);

    int total;
    cin >> total;
    while(total){
        cin >> que;
        cin >> ele;

        if(que == "add"){
            for(int i=1; i<=ele.length(); i++){
                string sub = ele.substr(0, i);

                if( !dh.get(sub) )
                    dh.set(sub, 1);
                else
                    dh.set(sub, dh.get(sub)+1);
            }

        }
        if(que == "find")
            cout<< dh.get(ele)<<endl;

        total--;
    }

    return 0;
}
