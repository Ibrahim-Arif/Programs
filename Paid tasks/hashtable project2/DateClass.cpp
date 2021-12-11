/*
 * DateClass.cpp
 *
 * Author: Samuel Mandada
 */


#include "date.h"

namespace patch
{
    template < typename T > std::string to_stringg( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

Date::Date(){}
Date::Date(int day, int month, int year){
    this->day = day;
    this->month = month;
    this->year = year;
}

void Date::create(){
    bool flag;

    flag = true;
        while(flag){
            cout << "Enter day(dd): ";
            cin >> day;

            if(day >= 1 && day <= 31)
                flag = false;
            else
                cout << "Invalid Day!! Day must be between 1-31." << endl;
        }

        flag = true;
        while(flag){
            cout << "Enter month(mm): ";
            cin >> month;

            if(month >= 1 && month <= 12)
                flag = false;
            else
                cout << "Invalid Month!! Month must be between 1-12." << endl;
        }

        flag = true;
        while(flag){
            cout << "Enter year(yyyy): ";
            cin >> year;

            if(year >= 1)
                flag = false;
            else
                cout << "Invalid Year!! Please enter year in Four digit format." << endl;
        }
}

string Date::toString(){
    return patch::to_stringg(day) + ":" + patch::to_stringg(month) + ":" + patch::to_stringg(year) + "\n";
}
