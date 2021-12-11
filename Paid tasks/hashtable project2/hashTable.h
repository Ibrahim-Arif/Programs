
/*
 * HashTable.h
 *
 * Author: Samuel Mandada
 */


#pragma once
#include <vector>
#include <ctime>
#include <cmath>
#include <bitset>
#include "date.h"
#include "theater.h"
using namespace std;

class HashTable{
private:
    const static int length_of_vector = 73;
    vector<Theater> table[length_of_vector];

    int hashIt(Date obj);
    void toBinary(long int num, int *binary);
    int toDecimal(int binary[32]);

public:
    HashTable();

    void read();
    void write();

    void insert();
    void find(Date obj);
    void printAll();
};
