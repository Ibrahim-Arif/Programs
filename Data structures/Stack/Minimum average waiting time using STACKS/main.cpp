#include <iostream>                 // https://www.hackerrank.com/challenges/minimum-average-waiting-time/problem
using namespace std;
class node{
public:
    int order_t, required_t;
    node(){}
    node(int o, int r){
        order_t = o;
        required_t = r;
    }
};

class Stack{
public:
    int top, capacity;
    node *arr;

    Stack(int c){
        capacity = c;
        top = -1;
        arr = new node[c];
    }

    void push(node ele){
        if(isFull()){
            cout << "Stack is overflow!" << endl;
            return;
        }
        arr[++top] = ele;
    }
    node pop(){
        node n;
        if(isEmpty()){
            return n;
        }
        else
            return arr[top--];
    }
    node peek(){
        node n;
        if(isEmpty())
            return n;
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
            cout << arr[i].order_t <<", "<<arr[i].required_t<< " ," ;
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
    int cap, ot, rt, sum=0, total=0;
    cin >> cap;
    Stack s(cap), s2(cap);

    while(cap){
        cin >> ot;
        cin >> rt;
        node n(ot, rt);

        if(s.isEmpty())
            s.push(n);
        else if(n.required_t < s.peek().required_t)
            s.push(n);
        else if(n.required_t > s.peek().required_t){
            while(n.required_t > s.peek().required_t && !s.isEmpty())
                s2.push(s.pop());
            s.push(n);
            while(!s2.isEmpty())
                s.push(s2.pop());
        }
        cap--;
    }

    cap = s.length();
    while( !s.isEmpty() ){
        node n = s.pop();
        sum += n.required_t;
        total += sum - n.order_t;
    }
    cout<<total/cap<<endl;

    return 0;
}
