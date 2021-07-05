#include<iostream>
#include<fstream>


using namespace std;


int main(){

    char buffer;
    ifstream iFile;
    iFile.open("source.txt");
    ofstream oFile;
    oFile.open("destination.txt");

    while(!iFile.eof()){
        iFile.get(buffer);
        if(buffer != 'a' || buffer != 'e' ||  buffer != 'i'|| buffer != 'o' || buffer != 'u'){
        oFile<<buffer;
        }

    }

    cout<<"DATA COPIED CHECK FILES";
    oFile.close();
    iFile.close();

}
