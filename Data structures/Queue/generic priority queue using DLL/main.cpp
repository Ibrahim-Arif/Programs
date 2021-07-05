#include <iostream>
using namespace std;

template<class T>
class node{
public:
    T data;
    int priority;
    node<T> *left;
    node<T> *right;

    node(){}
    node(T d, int p){
        data = d;
        priority = p;
        left = nullptr;
        right = nullptr;
    }
};

template<class T>
class priority_Q{
public:
    node<T> *rear, *front;
    priority_Q(){
        rear = front = nullptr;
    }

    void enQ(T ele, int prio){
        if(prio < 1 || prio > 5){
            cout<<"Wrong priority"<<endl;
            return;
        }

        node<T> *n = new node<T>(ele, prio);
        if(!rear){
            rear = front = n;
            return;
        }
        n->right = rear;
        rear->left = n;
        rear = n;

        adjust();
    }

    T dQ(){
        T value;
        node<T> *temp = front;

        if(temp)
            value = temp->data;
        else
            return -1;

        if(front == rear){
            delete temp;
            front = rear = nullptr;

            return value;
        }

        front = front->left;
        front->right = nullptr;
        delete temp;

        return value;
    }

    void adjust(){
        node<T> *temp = rear, *next;
        T hold;

        while(temp){
            next = temp->right;
            if(!next)
                return;

            if(temp->priority < next->priority){
                hold = temp->data;
                temp->data = next->data;
                next->data = hold;

                hold = temp->priority;
                temp->priority = next->priority;
                next->priority = hold;
            }

            temp = temp->right;
        }
    }
};



int main()
{
    priority_Q<int> pq;
    int ele, prio, choice;

    cout<<"1: Enqueue. \n2: Dequeue. \n0: Exit."<<endl;
    while(choice){
        cout<<"\nEnter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
                cout<<"Enter value, priority: ";
                cin >> ele;
                cin >> prio;
                pq.enQ(ele, prio);
                break;
            }
            case 2:{
                ele = pq.dQ();
                if(ele != -1)
                    cout<<"Dequeued: "<<ele<<endl;
                else
                    cout<<"Queue underflow!"<<endl;
                break;
            }
            case 0:{
                break;
            }
            default:{
                cout<<"Wrong choice!"<<endl;
                break;
            }
        }
    }
    return 0;
}
