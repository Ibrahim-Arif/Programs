#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    int totalDept = 17;
    string dept[totalDept] = {
        "BCS",
        "BCE",
        "BEE",
        "BAF",
        "BSE",
        "BBA",
        "BPH",
        "BPY",
        "BDE",
        "BSM",
        "BMC",
        "CHE",

        "PMS",

        "RCS",
        "RMT",
        "REE",
        "RPH",
    };

    string batchName[2] = {"SP", "FA"};
    string batchYear[5] = {"17", "18", "19", "20", "21"};


    for(int batchNameIndex = 0; batchNameIndex < 2; batchNameIndex++){
        for(int batchYearIndex = 0; batchYearIndex < 5; batchYearIndex++){

        cout << batchName[batchNameIndex] + batchYear[batchYearIndex] + ".dat" << endl;
        ofstream file(batchName[batchNameIndex] + batchYear[batchYearIndex] + ".dat");

            for(int deptIndex = 0; deptIndex < totalDept; deptIndex++){
                for(int SID = 1; SID <= 160; SID++){
                    file << batchName[batchNameIndex] << batchYear[batchYearIndex] << "-" << dept[deptIndex] << "-" ;

                    if(SID < 10)
                        file << "00";
                    else if(SID < 100)
                        file << "0";

                    file << SID << "@cuilahore.edu.pk" << endl;
                }
            }

            file.close();
        }
    }

    return 0;
}
