#include <iostream>
#define CAP 16
using namespace std;

class Node{
public:
    int priority;
    string name;

    Node(){}
    Node(int p, string n){
        priority = p;
        name = n;
    }
};

class Heap{
public:
    Node *heapp, *root;
    int index, tail, size;

    Heap(){
        heapp = new Node[CAP];
        size = CAP;
        root = NULL;
        index = 1;
        tail = CAP-1;
    }
    void insert(Node ele){
        if( !heapp[1].priority ){
            heapp[index++] = ele;
            return;
        }
        int i = index, j;
        Node temp;
        heapp[index] = ele;

        while(i != 1){
            j = i;
            i /= 2;
            if(ele.priority < heapp[i].priority){
                temp = heapp[i];
                heapp[i]= ele;
                heapp[j] = temp;
            }
        }
        index++;
    }
    int lChild(int i){
        return 2*i;
    }
    int rClild(int i){
        return (2*i)+1;
    }
    Node delete_top(){
        Node ele;
        if(index == 1){
            ele.priority = -1;
            return ele;
        }
        ele = heapp[1];                    // smallest element into last index, for sorting
        heapp[1] = heapp[--index];            // last element of heap to root (temporary)

        int i = 1, mini;
        Node temp;
        while(i < index){
            if(lChild(i)>index || rClild(i)>index)       break;          // if any index have no child then break;

            mini = heapp[lChild(i)].priority <= heapp[rClild(i)].priority ? lChild(i) : rClild(i);
            if(heapp[mini].priority <= heapp[i].priority){
                temp = heapp[i];
                heapp[i] = heapp[mini];
                heapp[mini] = temp;
            }
            i = mini;
        }
        heapp[tail--] = ele;

        return ele;
    }
};

class priority_queue{
public:
    Heap h;
    priority_queue(){}

    void enqueue(Node ele){
        if(h.index >= CAP){
            cout << "!!! Queue is full !!!" << endl;
            return;
        }

        h.insert(ele);
        h.root = &h.heapp[1];

        cout << "Patient \"" << ele.name << "\" added successfully..." << endl;
    }
    Node dequeue(){
        Node temp = h.delete_top();

        if(temp.priority == -1)
            cout << "!!! Queue is empty !!!" << endl;

        return temp;
    }
};

int main()
{
    int choice = -1;
    Node ele;
    priority_queue pq;

    cout << "1: Enqueue \n2: Dequeue \n0: Exit "<<endl;
    while(choice){
        cout<<"\nEnter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
                cout << "Enter patient name: ";
                cin >> ele.name;
                cout << "Enter patient priority: ";
                cin >> ele.priority;

                if(ele.priority < 1 || ele.priority > 15){
                    cout << "!!! Wrong priority !!!" << endl;
                    break;
                }

                pq.enqueue(ele);
                break;
            }
            case 2:{
                ele = pq.dequeue();
                if(ele.priority != -1){
                    cout << "Dequeued patient name: " << ele.name << endl;
                    cout << "Dequeued patient priority: " << ele.priority << endl;
                }
                break;
            }
            case 0:{
                break;
            }
            default:{
                cout << "Wrong Input !!!" << endl;
                break;
            }
        }
    }
    return 0;
}
