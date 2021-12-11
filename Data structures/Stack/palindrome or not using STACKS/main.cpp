#include <iostream>
#include <string>
#include <cmath>
using namespace std;

template<class T>
class Stack{
public:
    int top, capacity;
    T *arr;

    Stack(int c){
        capacity = c;
        top = -1;
        arr = new T[c];
    }
    void push(T ele){
        if(isFull()){
            cout << "Stack is overflow!" << endl;
            return;
        }
        arr[++top] = ele;
    }
    T pop(){
        if(isEmpty()){
            cout << "Stack is underflow!" << endl;
        }
        else
            return arr[top--];
    }
    T peek(){
        if(isEmpty()){
            cout << "Stack is underflow!" << endl;
        }
        else
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
    string ele;
    double length=0;
    char curr;
    bool flag = true;

    do{
        length =0;
        flag = true;

        cout<<"\nPlease enter the input expression: ";
        getline(cin, ele);
        getline(cin, ele);
        cout<<ele<<endl;

        int i=0;
        curr = ele[0];
        while(curr != '\0'){
            curr = ele[i++];
            if(isalpha(curr) || isdigit(curr))
                length++;
        }

        Stack<char> s(length);
        double half = length / 2;

        for(int i=0; i < ceil(half); i++){
            curr = ele[i];
            if(isalpha(curr) || isdigit(curr))
                s.push(curr);
        }

        s.pop();
        for(int i = (half+1); i<length; i++){
            curr = ele[i];
            if(isalpha(curr)){
                if(curr != s.pop()){
                    cout<<"the expression you added is not a palindrome."<<endl;
                    flag = false;
                    break;
                }
            }
        }
        if(flag)
            cout<<"the expression you added is a palindrome."<<endl;

        cout<<"\nDo you want to continue (y/n): ";
        cin >> curr;
    }while(curr == 'y');

    return 0;
}
