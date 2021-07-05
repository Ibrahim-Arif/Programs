#include <iostream>
using namespace std;

template<class T>
class circular_queue{
private:
    T *cqueue;
    int front = -1, rear = -1, capacity=0;

public:
    circular_queue(){}
    circular_queue(int cap){
        capacity = cap;
        cqueue = new T[cap];
    }

    void push(T ele){
        if( isFull() )
            cout << "Queue is full!" << endl;
        else if(front == -1 && rear == -1){
            front = rear = 0;
            cqueue[rear] = ele;
        }
        else if(rear == capacity-1){
            rear = 0;
            cqueue[rear] = ele;
        }
        else
            cqueue[++rear] = ele;
    }
    T pop(){
        T temp;
        if(isEmpty()){
            cout << "Queue is empty!" << endl;
            return -1;
        }
        else if(front == rear){
            temp = cqueue[front];
            front = rear = -1;
            return temp;
        }
        else if(front == capacity-1){
            temp = cqueue[front];
            front = 0;
            return temp;
        }
        else
            return cqueue[front++];
    }
    T peek(){
        if( isEmpty() ){
            cout<< "Queue is empty!" << endl;
            return -1;
        }
        return cqueue[front];
    }
    bool isEmpty(){
        return (front == -1 && rear == -1);
    }
    bool isFull(){
        return (front == rear+1) || (rear == capacity-1) && (front == 0);
    }
};

int main()
{
    int size, choice;
    int ele;

    cout<<"Size: ";
    cin >> size;
    circular_queue<int> cq(size);

    cout << "1: Push \n2: Pop \n3: Peek \n0: Quit" << endl;
    while(choice){
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
                cout << "Enter element: ";
                cin >> ele;
                cq.push(ele);
                break;
            }
            case 2:{
                ele = cq.pop();
                if(ele != -1)
                    cout<< "Pop element: " << ele <<endl;
                break;
            }
            case 3:{
                ele = cq.peek();
                if(ele != -1)
                    cout<< "Peek element: " << ele <<endl;
                break;
            }
            case 0:{
                break;
            }
            default:{
                cout << "Wrong input!"<<endl;
                break;
            }
        }
    }
    return 0;
}
