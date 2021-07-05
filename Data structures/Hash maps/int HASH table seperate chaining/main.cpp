#include <iostream>
#include <array>
#include <vector>
using namespace std;

class bucket{           // not bucket, it should be slot.
public:
    string key;
    int value;

    bucket(){
        key = "";
        value = 0;
    }
    bucket(string k, int v){
        key = k;
        value = v;
    }
};

class hashTable{
public:
    int cap;
    bucket **arr;

    hashTable(){}
    hashTable(int c){
        cap = c;
        arr = new bucket*[c]{};
    }

private:
    int _hash(string key){
        int hash = 0;

        for(int i=0; i<key.length(); i++)
            hash = (hash + int(key[i]) *i) % cap;

        return hash;
    }
public:
    void set(string key, int value){
        int address = _hash(key);

        if( !arr[address] )
            arr[address] = new bucket[5] {bucket()};

        int i=0;
        while(arr[address][i].value)
            i++;

        arr[address][i] = bucket(key, value);
    }
    int get(string key){
        int address = _hash(key);
        bucket *current_bucket = arr[address];

        int i=0;
        if(current_bucket){
            while(current_bucket[i].value){
                if(current_bucket[i].key == key)
                    return current_bucket[i].value;
                i++;
            }
        }
        return 0;
    }
    vector<string> keys(){
        vector<string> keys;
        for(int i=0; i<cap; i++){
            if(arr[i]){
                int j=0;
                while(arr[i][j].value){
                    keys.push_back(arr[i][j].key);
                    j++;
                }
            }
        }
        return keys;
    }
};

int main()
{
    hashTable ht(50);

    ht.set("grapes", 1000);
    ht.set("apple", 50);
    ht.set("strawberry", 100);
    ht.set("banana", 500);

    cout<< ht.get("grapes")<<endl;
    cout<< ht.get("apple")<<endl;
    cout<< ht.get("strawberry")<<endl;

    vector<string> keys = ht.keys();
    for(int i=0; i<keys.size(); i++)
        cout<< keys[i] << ", ";

    return 0;
}
