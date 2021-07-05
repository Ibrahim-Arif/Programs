

/*
 * theater.cpp
 *
 * Author: Samuel Mandada
 */

#include "theater.h"

namespace patch
{
    template < typename T > std::string to_string2( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

using namespace std;

    Theater::Theater(int d, int m, int y,int co, int se, string c, string n){
        date.day = d;
        date.month = m;
        date.year = y;
        cost = co;
        seat = se;
        code = c;
        name = n;
    }
    Theater::Theater(Date d, int co, int se, string c, string n){
        date = d;
        seat = se;
        cost = co;
        code = c;
        name = n;
    }


    bool Theater::isMyDate(Date obj){
        if(obj.day == date.day && obj.month == date.month && obj.year == date.year)
            return true;
        return false;
    }
    string Theater::toString(){
        string temp = "";

        temp = "Name: " + name + "\t";
        temp += "Date: " + date.toString();
        temp += "Seat: " + patch::to_string2(seat) + "\tCost: " + patch::to_string2(cost) + "\tCode: " + code + "\n";

        return temp;
    }
    void Theater::toFile(){
        ofstream file;
        file.open("data.dat", std::ios_base::app);

        if(!file){
            cout << "Failed to write Data file" << endl;
            return;
        }

        file << name;
        file << " ";

        file << date.day;
        file << " ";

        file << date.month;
        file << " ";

        file << date.year;
        file << " \n";

        file << cost;
        file << " ";

        file << code;
        file << " ";

        file << seat;
        file << " ";

        file.close();
    }
