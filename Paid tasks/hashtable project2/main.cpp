
//============================================================================
// Name        : Main.cpp
// Proeject    : MovieLib
// Author      : Samuel Mandada
// Version     : 1.0
// Description : Movie Theatre Management System using hashtables
//============================================================================


#include <iostream>
#include "DateClass.cpp"
#include "TheaterClass.cpp"
#include "HashTableClass.cpp"

using namespace std;

int main()
{
    HashTable table;
    table.read();

    int choice = -1;
    cout << "\n1: Insert \n2: Find \n3: Print All \n0: Exit" << endl;
    while(choice){
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
                table.insert();
                break;
            }
            case 2:{
                Date date;
                date.create();
		cout << "\nSearching result for " << date.toString();
                table.find(date);
                break;
            }
            case 3:{
                table.printAll();
                break;
            }
            case 0:{
                table.write();
                cout << "\nGoodBye...";
                break;
            }
            default :{
                cout << "Wrong Input !!" << endl;
                break;
            }
        }
    }
    return 0;
}
