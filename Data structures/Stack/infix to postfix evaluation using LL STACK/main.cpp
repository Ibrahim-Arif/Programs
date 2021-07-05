#include <iostream>
#include<string>
#include <cmath>
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
class Stack{
private:
    int size;
    node<T> *head, *n;
public:
    Stack(){
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
        if(!isEmpty()){
            n = head;
            head = head->link;
            size--;
            return n->data;
        }
    }
    T peek(){
        if( !isEmpty() )
            return head->data;
    }
    bool isEmpty(){
        return (!size) ? true : false;
    }
};

bool isCorrectExpression(string infix){
    Stack<char> s;
    int i=0;
    char curr;

    while(infix[i] != '\0'){
        curr = infix[i];

        if(curr == '(')
            s.push(curr);
        if(curr == ')'){
            if(s.isEmpty())
                return false;
            else
                s.pop();
        }
        i++;
    }
    return s.isEmpty();
}

int precedence(char op){
    if(op == '(' || op == ')' || op == '{' || op == '}')               return 4;
    else if(op == '^')                                                            return 3;
    else if(op == '*' || op == '/' || op == '%')                      return 2;
    else if(op == '+' || op == '-')                                         return 1;
}

string convertToPostfix(string str){
    int i=0;
    string postfix="";
    Stack<char> s;
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
            return second - first; // need a if here
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
    Stack<int> s;
    char curr;
    int i=0;
    while( postfix[i] != '\0' ){
        curr = postfix[i++];
        if(isdigit(curr))
            s.push( curr-'0' );
        else
            s.push( arithmetic(s.pop(), curr, s.pop()) );
    }
    return s.pop();
}

int main()
{
    string infix, postfix;
    char choice;

    do{
        cout << "Enter algebric expression in infix: ";
        getline(cin, infix);
        getline(cin, infix);
        cout<< "The expression was: " << infix << endl;

        if( !isCorrectExpression(infix) ){
            cout<< "\nAlert! Statement is incorrect. "<<endl;
        }
        else{
            postfix = convertToPostfix(infix);
            cout << "\nThe expression converted to postfix is: "<<postfix<<endl;

            cout<< "The evaluated postfix expression is: ";
            cout<< postfixEvaluation(postfix)<<endl;
        }

        cout<< "\nDo you want to enter another expression (y/n): ";
        cin >> choice;
    }while(choice == 'y');

    cout<<"Thank you for using this expression convertor and evaluator."<<endl;
    return 0;
}
