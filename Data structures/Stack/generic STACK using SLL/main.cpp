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
class stack{
private:
    int size;
    node<T> *head, *n;
public:
    stack(){
        size = 0;
        head = nullptr;
    }
    void push(T ele){
        n = new node<T>(ele);
        if(!head){
            head = n;
        }else{
            n->link = head;
            head = n;
        }
        size++;
    }
    T pop(){
        if( isEmpty() )
            return -1;
        n = head;
        head = head->link;
        size--;
        return n->data;
    }
    T peek(){
        if( isEmpty() )
            return -1;
        return head->data;
    }
    bool isEmpty(){
        return (!size) ? true : false;
    }
};

int main()
{
    int choice;
    int ele;
    stack<int> stk;

    cout << "1: Push. \n2: Pop. \n3: Peek. \n0: Exit." << endl;
     while(choice){
        cout<<"\nEnter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
                cout << "Enter data: ";
                cin >> ele;
                stk.push(ele);
                break;
            } case 2:{
                cout << "Pop element: "<< stk.pop() << endl;
                break;
            } case 3:{
                cout<< "Peek element: "<<stk.peek()<<endl;
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
