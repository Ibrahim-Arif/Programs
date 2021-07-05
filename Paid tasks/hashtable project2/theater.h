
/*
 * theater.h
 *
 * Author: Samuel Mandada
 */

#ifndef THEATER_H_
#define THEATER_H_

#pragma once
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "date.h"

using namespace std;

class Theater {
public:
    string code;
	string name;
	Date date;
	int cost=0;
	int seat=60;

	Theater(int d, int m, int y, int co, int se, string c, string n);
    Theater(Date d, int co, int se, string c, string n);

	void find();
	bool isMyDate(Date obj);
    string toString();
	void toFile();
};

#endif /* THEATER_H_ */
