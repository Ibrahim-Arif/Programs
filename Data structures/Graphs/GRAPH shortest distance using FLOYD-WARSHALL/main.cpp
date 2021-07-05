#include <iostream>
#include <bits/stdc++.h>
#define MAX 99999
#define size 4
using namespace std;

void print(int arr[size][size]){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++)
            if(arr[i][j] == MAX)
                cout<<"INF,\t";
            else
                cout<< arr[i][j] << ",\t";
        cout<<endl;
    }
}

int main()
{
    /*int arr[size][size] =  { {0,     3,          MAX,    7},
                                        {8,     0,          2,           MAX},
                                        {5,     MAX,    0,          1},
                                        {2,     MAX,    MAX,    0} };*/

    int arr[size][size] = { {0,   5,  MAX, 10},
                                        {MAX,  0,  3,  MAX},
                                        {MAX, MAX, 0,   1},
                                        {MAX, MAX, MAX, 0} };

    for(int k=0; k<size; k++){
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                if( arr[i][j] > (arr[i][k] + arr[k][j] ) )
                    arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }

    print(arr);
    return 0;
}
