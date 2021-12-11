#include <iostream>
#include <time.h>
using namespace std;

class customArray{
private:
    int index, siz;

public:
    int *arr;

    customArray(){
        arr = new int[20];
        siz = 20;
        index=0;
    }
    customArray(int s){
        arr = new int[s];
        siz = s;
        index=0;
    }

    void pushBack(int value){
        if(index == siz){
            cout<<"overflow"<<endl;
            arr = reSize();
        }
        arr[index++] = value;
    }
    int* reSize(){
        siz *= 2;
        int *temp = new int[siz];
        for(int i=0; i<index; i++)
            temp[i] = arr[i];
        return temp;
    }
    int indexAt(int i){
        return arr[i];
    }
    void setAt(int i, int value){
        arr[i] = value;
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

customArray merge(customArray left, int pivotEle, customArray right){
    int siz = left.size() + right.size() + 2;
    customArray arr(siz);

    for(int i=0; i<left.size(); i++)
        arr.pushBack(left.indexAt(i));
    arr.pushBack(pivotEle);
    for(int i=0; i<right.size(); i++)
        arr.pushBack(right.indexAt(i));

    return arr;
}

customArray quickSort(customArray arr){
    if(arr.size()==1 || !arr.size())
        return arr;

    int pivot = arr.size() - 1;
    int temp, pivotEle, currEle;

    if(arr.size() == 2){
        pivotEle = arr.indexAt(pivot);
        currEle = arr.indexAt(0);
        if(currEle > pivotEle){
            arr.setAt(0, pivotEle);
            arr.setAt(1, currEle);
        }
        return arr;
    }

    for(int i=0; i<=pivot; i++){
        currEle = arr.indexAt(i);
        pivotEle = arr.indexAt(pivot);

        if(currEle > pivotEle){
            temp = currEle;
            arr.setAt(i, arr.indexAt(pivot-1));
            arr.setAt(pivot-1, pivotEle);
            arr.setAt(pivot, temp);
            pivot--;
            i--;
        }
    }

    customArray left(pivot),
                           right(arr.size() - pivot);

    for(int i=0; i<pivot; i++)
        left.pushBack(arr.indexAt(i));
    for(int i=pivot+1; i<arr.size(); i++)
        right.pushBack(arr.indexAt(i));

    return merge(quickSort(left), pivotEle, quickSort(right));
}


int main()
{
    srand(time(0));                                             // limit is 5 lac
    int s = 500000;
    //int a[] = {3, 7, 8, 5, 2, 1, 9, 5, 4};
    //int a[] = {4, 6, 2, 66, 7, 11, 1, 9};
    customArray arr(s);

    for(int i=0; i<s; i++)
        arr.pushBack((rand()%s) +1) ;

    //arr.print();
    quickSort(arr).print();
    //quickSort(arr);

    cout<<"\nEnded";
    return 0;
}
