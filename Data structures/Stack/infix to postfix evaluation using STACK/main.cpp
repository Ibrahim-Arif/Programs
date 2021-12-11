#include <iostream>
#include<string>
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
        if(isEmpty())
            cout << "Stack is underflow!" << endl;
        else
            return arr[top];
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

int precedence(char op){
    if(op == '(' || op == ')' || op == '{' || op == '}')               return 4;
    else if(op == '^')                                                            return 3;
    else if(op == '*' || op == '/' || op == '%')                      return 2;
    else if(op == '+' || op == '-')                                         return 1;
}
string convertToPostfix(string str){
    int i=0;
    string postfix="";
    Stack<char> s(str.length());
    char curr;

     while(str[i] != '\0'){
        curr = str[i];
        if(isspace(curr)){
            ++i;
            continue;
        }
        if( isalpha(curr) || isdigit(curr) )
            postfix += curr;
        else if( s.isEmpty() || s.peek() == '(')
            s.push(curr);
        else if(curr == '(')
            s.push(curr);
        else if( curr == ')' ){
            char po = s.pop();
            while(po != '('){
                postfix += po;
                po = s.pop();
            }
        }
        else if(precedence(curr) > precedence( s.peek() ))
            s.push(curr);
        else if(precedence(curr) < precedence( s.peek() )){
            postfix += s.pop();
            continue;                    // pop until prec( curr ) > prec( stack.peek )
            s.push(curr);
        }
        else if(precedence(curr) == precedence( s.peek() )){
            s.push(curr);
            if(precedence(curr) != 3)
                postfix += s.pop();
        }
        ++i;
    }
    while(!s.isEmpty())
        postfix += s.pop();

    return postfix;
}
int arithmetic(int second, char oper, int first){
    switch(oper){
        case '+':
            return first + second;
        case '-':
            return first - second;
        case '*':
            return first * second;
        case '/':
            return (second>first)? (second / first) : (first / second);
        case '%':
            return remainder(second, first);
        case '^':
            return pow(first, second);
    }
}
int postfixEvaluation(string postfix){
    Stack<int> stack(postfix.length());
    char curr;
    int i=0;
    while( postfix[i] != '\0' ){
        curr = postfix[i++];
        if(isdigit(curr))
            stack.push( curr-'0' );
        else
            stack.push( arithmetic(stack.pop(), curr, stack.pop()) );
    }
    return stack.pop();
}

int main()
{
    string infix, postfix, type;
    char choice;

    do{
        cout << "\nInput for numeric or algebraic: ";
        cin >> type;
        cout << "Enter expression to postfix: ";
        getline(cin, infix);
        getline(cin, infix);
        cout<< "The expression was: "<<infix<<endl;

        postfix = convertToPostfix(infix);
        cout << "\nThe expression converted to postfix is: "<<postfix<<endl;

        if(type == "numeric"){
            cout<< "The evaluated postfix expression is: ";
            cout<< postfixEvaluation(postfix)<<endl;
        }

        cout<< "\nDo you want to enter another expression (y/n): ";
        cin >> choice;
    }while(choice == 'y');

    cout<<"Thank you for using this expression convertor and evaluator."<<endl;
    return 0;
}
