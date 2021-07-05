#include <iostream>
using namespace std;

template<class T>
class heap{
public:
    T *heapp, *root;
    int index, tail, size;

    heap(int cap){
        heapp = new T[cap];
        size = cap;
        root = nullptr;
        index = 1;
        tail = cap-1;
    }

    void    insert(T ele){
        if( !heapp[1] ){
            heapp[index++] = ele;
            return;
        }
        int i = index, j, temp;
        heapp[index] = ele;

        while(i != 1){
            j = i;                                  //previous index of last greatest swap
            i /= 2;                                // parent of i = i/2
            if(ele < heapp[i]){              // '< ' for min heap
                temp = heapp[i];
                heapp[i]= ele;
                heapp[j] = temp;
            }
        }
        index++;
    }
    void    display(){
        if(index == 1){
            cout << "heap is empty!" << endl;
            return;
        }
        for(int i=1; i<index; i++)
            cout << heapp[i] << ", " ;
        cout << endl;
    }
    int       min(int a, int b){
        return (heapp[a] < heapp[b]) ? a : b;
    }
    int       leftChild(int i){
        return 2*i;
    }
    int       rightChild(int i){
        return (2*i)+1;
    }
    T        delete_top(){
        if(index == 1){
            return -1;
        }
        int ele = heapp[1];
        heapp[tail--] = ele;                 //largest element into last index, for sorting
        heapp[1] = heapp[--index];            //last element of heap to root (temporary)

        int i = 1, mini;
        T temp;
        while(i < index){
            if(leftChild(i)>index || rightChild(i)>index)       break;          // if any index have no child then break;

            mini = min( leftChild(i), rightChild(i) );
            if(heapp[mini] < heapp[i]){
                temp = heapp[i];
                heapp[i] = heapp[mini];
                heapp[mini] = temp;
            }
            i = mini;
        }
        return ele;
    }
    T         min_ele(){
        return heapp[1];
    }
};

int size_of(int *arr){
    int i=0;
    while( *(arr+i) != 0)
        i++;
    return i;
}
int* sort_array(int *arr){
    int length = size_of(arr);
    heap<int> h(length*2);

    for(int i=0; i<length; i++)
        h.insert( *(arr+i) );

    for(int i=0; i< length; i++)
        *(arr + i) = h.delete_top();

    return arr;
}

int main()
{
    int n, length;
    double result;
    cin >> n;
    int *arr = new int[n+1]{0};

    for(int i=0; i<n; i++){
        cin >> arr[i];
        arr = sort_array(arr);

        length = size_of(arr);
        if(length % 2)
            result = (double)arr[length/2];
        else
            result = (double)(arr[length/2] + arr[ (length/2)-1 ])/2;

        printf("%.1f \n",result);
    }
    return 0;
}
