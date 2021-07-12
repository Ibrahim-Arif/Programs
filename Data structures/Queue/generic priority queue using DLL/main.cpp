#include <iostream>
using namespace std;

template<class T>
class Node{
public:
    T data;
    int priority;
    Node<T> *left;
    Node<T> *right;

    Node(){}
    Node(T d, int p){
        data = d;
        priority = p;
        left = NULL;
        right = NULL;
    }
};

template<class T>
class priority_Q{
public:
    Node<T> *rear, *front;
    priority_Q(){
        rear = front = NULL;
    }

    void enQ(T ele, int prio){
        Node<T> *n = new Node<T>(ele, prio);
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
        Node<T> *temp = front;

        if(temp)
            value = temp->data;
        else
            return -1;

        if(front == rear){
            delete temp;
            front = rear = NULL;

            return value;
        }

        front = front->left;
        front->right = NULL;
        delete temp;

        return value;
    }

    void adjust(){
        Node<T> *temp = rear, *next;
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
    int ele, prio, choice=1;

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
