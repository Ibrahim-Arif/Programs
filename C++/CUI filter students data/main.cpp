#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void filterDirtyDataToGetAll(){
    char ch, temp;
    bool isWrite = false;

    fstream fin("studentsDirtyData.txt", fstream::in);
    fstream foutput("allEmails.dat", fstream::out);

    while (fin >> noskipws >> ch) {
        if(isWrite && ch != '>')
            foutput << ch;

        if(ch == '<'){
            isWrite = true;
        }else if(ch == '>'){
            foutput << endl;
            isWrite = false;
        }
    }

    fin.close();
    foutput.close();

    cout << "Dirty Data filtered All emails get successfully..." << endl;

}
void filterDirtyData(){
    char ch, temp;
    bool isWrite = false;

    fstream fin("studentsDirtyData.txt", fstream::in);
    fstream foutput("studentsNamesAndEmails.dat", fstream::out);

    while (fin >> noskipws >> ch) {
        if(isWrite && ch != '<' && ch != '>' && ch != '"'){
            foutput << ch;
            //cout << ch;
        }

        if(ch == ','){
            isWrite = true;
            fin >> noskipws >> temp;
        }else if(ch == '<'){
            //cout << "\t\t\t\t";
            foutput << "\t\t\t\t";
        }else if(ch == '>'){
            //cout << endl;
            foutput << endl;
            isWrite = false;
        }
    }

    fin.close();
    foutput.close();

    cout << "Dirty Data filtered successfully..." << endl;
}
void filterAllEmails(){
    fstream fin("allEmails.dat", fstream::in);
    fstream foutput("studentEmails.dat", fstream::out);
    fstream foutput2("otherEmails.dat", fstream::out);

    string email;

    while(getline(fin, email)){
        if( (email.at(0)=='s' && email.at(1)=='p') || (email.at(0)=='f' && email.at(1)=='a') ){
            if( (email.at(2)-'0'==1 || email.at(2)-'0'==2) )
                foutput << email << endl;
        }
        else{
            foutput2 << email << endl;
        }
    }

    fin.close();
    foutput.close();
    foutput2.close();

    cout << "Students emails generated successfully..." << endl;
}

int main()
{
    //filterDirtyData();
    filterAllEmails();
    //filterDirtyDataToGetAll();


    return 0;
}
