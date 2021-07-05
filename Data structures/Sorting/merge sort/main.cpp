#include <iostream>
#include <cmath>
#include<ctime>
using namespace std;

class customArray{
public:
    int *arr, index, siz;

    customArray(int s){
        arr = new int[s];
        siz = s;
        index=0;
    }
    customArray(){
        arr = new int[20];
        siz = 20;
        index=0;
    }

    void pushBack(int value){
        if(index == siz)
            arr = reSize();

        arr[index++] = value;
    }
    int* reSize(){
        siz *= 2;
        int *temp = new int[siz];
        for(int i=0; i<index; i++)
            temp[i] = arr[i];
        return temp;
    }
    int size(){
        return index;
    }
    void print(){
        for(int i=0; i<index; i++)
            cout<<arr[i]<<", ";
        cout<<endl;
    }
};

int size(int arr[]){
    int count=0;
    while(arr[count] != 0)
        count++;
    return count;
}
void print(int *arr){
    int i=0;
    while(arr[i] != 0)
        cout<<arr[i++]<<", ";
    cout<<endl;
}

int* merge(int left[], int right[]){
    int leftSize        = size(left),
         rightSize      = size(right),
         leftIndex      =0,
         rightIndex    =0;

    customArray result(leftSize+rightSize+1);               // result array will be arranged combination of left, right.
                                                                                           // so its size will be sum of them and +1 is for '0' at the end

    while(leftIndex<leftSize && rightIndex<rightSize){
        if(left[leftIndex] < right[rightIndex])
            result.pushBack(left[leftIndex++]);
        else
            result.pushBack(right[rightIndex++]);
    }

    while(left[leftIndex] != 0)                                             // pushing in case if left or right still have unvisited elements.
        result.pushBack(left[leftIndex++]);
    while(right[rightIndex] != 0)
        result.pushBack(right[rightIndex++]);

    result.pushBack(0);
    return result.arr;
}

int* mergeSort(int arr[]){
    int s = size(arr);
    double mid = ceil(s / 2);

    if(s == 1)                              // (base case) when array is divided into units
        return arr;

    customArray left(mid*2),
                           right(mid*2);

    for(int i=0; i<mid; i++)                // left half of array
        left.pushBack(arr[i]);
    left.pushBack(0);                       // last element as '0'

    for(int i=mid; i<s; i++)             // right half of array
        right.pushBack(arr[i]);
    right.pushBack(0);                  // last element as '0'

    return merge(
        mergeSort(left.arr),
        mergeSort(right.arr)
    );
}

int main()                                       // not working with repeated data
{                                                      // input array MUST end with '0'
    srand(time(0));

    //int arr[] = {78, 46, 23, 99, 2, 11, 108, 77, 0};  //8
    //int arr[] = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};    //10
    int arr[] = {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};   //16
    //int arr[] = {99, 99, 99, 99, 99, 99, 99, 99, 99, 0};

/*
    int n= 5000000;
    int *arr = new int[n+1];

    for(int i=0; i<n; i++)
        arr[i] = rand() % 5000 +1;
    arr[n] = 0;
*/

    int *sorted = mergeSort(arr);
    print(sorted);

    cout<<"\nEnded";
    return 0;
}
