#include <iostream>
using namespace std;

template<class T>
class node{
public:
    T data;
    node *link;
    node(){}
    node(T d){
        data = d;
        link = nullptr;
    }
};

template<class T>
class queue{
private:
    int size;
    node<T> *head, *tail, *n;
public:
    queue(){
        size = 0;
        head = nullptr;
    }
    void push(T ele){
        n = new node<T>(ele);
        if(!head){
            head = n;
            tail = n;
        } else{
            tail->link = n;
            tail = n;
        }
        size++;
    }
    T pop(){
        if(!size)
            return -1;
        n = head;
        head = head->link;
        size--;
        return n->data;
    }
    T peek(){
        if(!size)
            return -1;
        return head->data;
    }
};

int main()
{
    int choice;
    int ele;
    queue<int> q;

    cout << "1: Push. \n2: Pop. \n3: Peek. \n0: Exit." << endl;
     while(choice){
        cout<<"\nEnter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
                cout << "Enter data: ";
                cin >> ele;
                q.push(ele);
                break;
            } case 2:{
                cout << "Pop element: "<< q.pop() << endl;
                break;
            } case 3:{
                cout<< "Peek element: "<<q.peek()<<endl;
                break;
            } case 0:{
                break;
            } default :{
                cout<<"wrong input!" <<endl;
                break;
            }
        }
     }
    return 0;
}
