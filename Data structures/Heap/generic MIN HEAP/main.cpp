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
            j = i;                                  //previous index of last smallest swap
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
    void    delete_top(){
        if(index == 1){
            cout<< "Heap is empty!"<<endl;
            return;
        }
        int ele = heapp[1];                           // smallest element into last index, for sorting
        cout<<ele<<endl;
        heapp[1] = heapp[--index];            // last element of heap to root (temporary)

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
        heapp[tail--] = ele;
    }
    void    sorted(){
        if(tail == size-1){
            cout << "Nothing sorted yet!"<<endl;
            return;
        }
        cout<< "Sorted elements are: "<<endl;
        for(int i=size-1; i>tail; i--){
            cout << heapp[i] <<", " ;
        }
        cout << endl;
    }
    void    search(T ele){
        for(int i=1; i<index; i++){
            if(ele == heapp[i])
                cout << ele<< " found! "<<endl;
        }
    }
};

int main()
{
    int choice = -1;
     int ele;
     heap<int> heap(10);

    cout << "1: Insert \n2: Delete top \n3: Search \n4: Display \n5: Sorted \n0: Exit "<<endl;
    while(choice){
        cout<<"\nEnter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
                cout<<"Enter element: ";
                cin >> ele;
                heap.insert(ele);
                heap.root = &heap.heapp[1];
                break;
            }
            case 2:{
                heap.delete_top();
                break;
            }
            case 3:{
                cout<<"Enter element to search: ";
                cin >> ele;
                heap.search(ele);
                break;
            }
            case 4:{
                heap.display();
                break;
            }
            case 5:{
                heap.sorted();
                break;
            }
            case 0:{
                break;
            }
            default:{
                printf("Wrong input!");
            }
        }
    }
    return 0;
}
