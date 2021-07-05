#include <iostream>
using namespace std;

class Stack{
public:
    int top, capacity, *arr;

    Stack(int c){
        capacity = c;
        top = -1;
        arr = new int[c];
    }
    void push(int ele){
        if(isFull()){
            cout << "Stack is overflow!" << endl;
            return;
        }
        arr[++top] = ele;
    }
    int pop(){
        if(isEmpty()){
            cout << "Stack is underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }
    int peek(){
        if(isEmpty()){
            cout << "Stack is underflow!" << endl;
            return -1;
        }
        return arr[top];
    }
    void traverse(){
        if(isEmpty()){
            cout << "Stack is underflow!";
            return;
        }
        cout << "Stack elements: " << endl;
        for(int i=top; i>=0; i--)
            cout << arr[i] << " ," ;
        cout << endl;
    }
    bool isEmpty(){
        if(top == -1)   return true;
        return false;
    }
    bool isFull(){
        if(top == capacity-1)   return true;
        return false;
    }
    int length(){
        return top+1;
    }
};

int main()
{
    int choice, capacity, ele;
    cout<< "Enter capacity: ";
    cin >> capacity;
    Stack stack(capacity);

    cout << "1: Push \n2: Pop \n3: Peek \n4: Traverse \n5: Length \n0: EXIT" << endl;
    while(choice != 0){
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter element: ";
                cin >> ele;
                stack.push(ele);
                break;
             case 2:
                ele = stack.pop();
                if(ele != -1)
                    cout << "Pop element: " << ele << endl;
                break;
             case 3:
                ele = stack.peek();
                if(ele != -1)
                    cout << "Peek element: " << ele << endl;
                break;
            case 4:
                stack.traverse();
                break;
            case 5:
                cout << "Current length: " << stack.length() << endl;
                break;
            case 0:
                break;
            default:
                cout << "Wrong choice !" << endl;
        }
    }
    return 0;
}
