#include <iostream>                         // https://www.hackerrank.com/challenges/poisonous-plants/problem
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
    bool flag = false;
    int n, curr, left, count=0;

    cin >> n;
    int arr[n];
    Stack<int> s1(n), s2(n);

    for(int i=0; i<n; i++)
        cin >> arr[i];

    for(int i=n-1; i>-1; i--){
        if(arr[i]  > arr[i-1] && i>0)
            flag = true;
         s1.push( arr[i] );
    }

    while(flag){
        count++;
        flag = false;
        left = 999999;
        curr = 0;

        while( !s1.isEmpty() ){
            curr = s1.pop();
            if(left >= curr)
                s2.push(curr);

            left = curr;
        }

        left = 0;
        while( !s2.isEmpty() ){
            curr = s2.pop();
            if(curr < left)
                 flag = true;

            s1.push(curr);
            left = curr;
        }
    }

    cout<<count<<endl;
    return 0;
}
