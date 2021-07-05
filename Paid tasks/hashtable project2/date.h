/*
 * Date.h
 *
 * Author: Samuel Mandada
 */


#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Date{
public:
    int day, month, year;

    Date();
    Date(int day, int month, int year);

    void create();
    string toString();
};
