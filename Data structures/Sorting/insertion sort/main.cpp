#include <iostream>
#include <limits>
#include <time.h>
#define size 55000
using namespace std;

template<class T>
class insertionSort{
public:
    void display(T *arr, int length){
        int i=0;
        while(i != length)
            cout<<arr[i++]<<", ";
        cout<<endl;
    }

    void iSort( T *arr, T value, int index ){
        int i=0;
        while(value > arr[i])                        // reaching to the position of insertion
            i++;
        for(int j=index+1; j>i; j--)                // creating one blank space for insertion by shifting right the remaining array
            arr[j] = arr[j-1];

        arr[i] = value;
        display(arr);                                    // ------- remove it -----------
    }

    void arrayISort(T *arr, int length){    // for array sorting
        int curr;
        for(int i=0; i<length; i++){
            curr = arr[i];

            int j = i-1;
            while(curr < arr[j] && j>=0){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = curr;
        }
    }
};

int main()
{
    srand(time(0));
    insertionSort<int> is;
    //int arr[20] = {numeric_limits<int>::max()};
    //char value=0;
    //int value=0;
    /*int i=0;

    while(value != -1){
        cin>>value;

        if(value != -1)
            is.iSort(arr, value, ++i);
    }*/

    //int arr[] = {48, 24, 12, 45, 67, 3, 11, 80, 120, 34, 300, 1};
    //int arr[] = {12, 11, 10, 9, 8, 7, 6, 5, 4,3, 2, 1};
    int n = 200000;
    int *arr = new int[n];

    for(int i=0; i<n; i++)
        arr[i] = rand()%n +1;

    is.arrayISort(arr, n);

    //is.display(arr, n);
    cout<<"Ended"<<endl;
    return 0;
}
