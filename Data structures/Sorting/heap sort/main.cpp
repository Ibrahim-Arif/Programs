#include <iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

template<class T>
class heap{
public:
    T *heapp;
    int size, tail;

    heap(){}
    heap(int cap){
        heapp = new T[cap];
        tail = cap-1;
        size = cap;
    }

    int       max(int a, int b){
        return (heapp[a] > heapp[b]) ? a : b;
    }
    int       leftChild(int i){
        return (2*i)+1;
    }
    int       rightChild(int i){
        return (2*i)+2;
    }
    int       parent(int i){
        return (i-1)/2;
    }
    void    search(T ele){
        for(int i=1; i<size; i++){
            if(ele == heapp[i])
                cout << ele << " found!" << endl;
        }
    }
    void    set(int i, int last){
        int maxi;
        T temp;
        if(leftChild(i)>last && rightChild(i)>last)     return;

        maxi = max( leftChild(i), rightChild(i) );
        if( heapp[maxi] > heapp[i]){
            temp = heapp[i];
            heapp[i] = heapp[maxi];
            heapp[maxi] = temp;

            set(maxi, last);            //after sorting, if again sorting is required on child
        }
    }
    void    heapify(int length){
        if(length == 0)     return;

        int last = length-1;
        int par, i = last;

        par = parent(i);
        while(i > -1){
            set(par, last);

            i = --par;
            par = i;
        }
    }
    void    delete_top(){
        if(tail < 0) {
            printf("Heap is empty!");
            return;
        }
        T temp = heapp[0];
        heapp[0] = heapp[tail];
        heapp[tail--] = temp;

        set(0, tail-1);                         //set new root to its position
    }
    void    sorted_display(){
        if(tail == size-1){
            printf("Nothing sorted yet! \n");
            return;
        }
        for(int i=size-1; i>=tail; i--)
            cout<<heapp[i]<<", ";
        cout<<endl;
        return;
    }
    void    display(){
        for(int i=0; i<=tail; i++)
            cout << heapp[i] << ", ";
        cout << endl;
    }
};

int main()
{
    int choice;
    heap<int> *h;
    int ele;
    srand(time(0));
    printf("1: Generate and Heapify \n2: Delete \n3: Search \n4: Display \n5: Sort \n0: Exit \n");
    while(choice){
        printf("\nEnter your choice: ");
        cin >> choice;

        switch(choice){
            case 1:{
                printf("Enter length of array to generate: ");
                cin >> ele;
                h = new heap<int>(ele);

                for(int i=0; i<ele; i++)
                    h->heapp[i] = 1 +rand()%100;
                break;
            }
            case 2:{
                h->delete_top();
                break;
            }
            case 3:{
                printf("Enter element to search: ");
                cin >> ele;
                h->search(ele);
                break;
            }
            case 4:{
                h->display();
                break;
            }
            case 5:{
                while(h->tail != 0)
                    h->delete_top();
                h->sorted_display();
                break;
            }
            case 0:{
                break;
            }
            default:{
                printf("Wrong input!");
                break;
            }
        }
    }
    return 0;
}
