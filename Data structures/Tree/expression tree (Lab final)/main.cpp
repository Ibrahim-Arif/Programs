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
class treeNode{
public:
    T data;
    treeNode *left, *right;
    treeNode(){
        left = right = nullptr;
    }
    treeNode(T d){
        data = d;
        left = right = nullptr;
    }
};

template<class T>
class Queue{
private:
    int size;
    node<T> *head, *tail, *n;
public:
    Queue(){
        size = 0;
        head = nullptr;
        tail = nullptr;
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
            return NULL;
        n = head;
        head = head->link;
        size--;
        return n->data;
    }
    T peek(){
        if(!size)
            return NULL;
        return head->data;
    }
    bool isEmpty(){
        return (!size) ? true : false;
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
            return NULL;
        n = head;
        head = head->link;
        size--;
        return n->data;
    }
    T peek(){
        if( isEmpty() )
            return NULL;
        return head->data;
    }
    bool isEmpty(){
        return (!size) ? true : false;
    }
};


template <class T>
class expressionTree{
public:
    treeNode<T> *root;
    expressionTree(){
        root = nullptr;
    }

    treeNode<T>* genereteExpTree(string postfix){
        stack<treeNode<T>*> nodeS;
        T curr = postfix[0];
        int i=0;

        while(postfix[i] != '\0'){
            curr = postfix[i++];

            if(isspace(curr))
                continue;

            treeNode<T> *temp = new treeNode<T>(curr);

            if(isdigit(curr) || isalpha(curr)){
                nodeS.push(temp);

            }else{
                temp->right = nodeS.pop();
                temp->left = nodeS.pop();

                nodeS.push(temp);
            }
        }
        root = nodeS.pop();
    }

    void infix(treeNode<T> *tree){
        if(!tree)
            return;

        if(tree->left)
            infix(tree->left);
        cout<<tree->data;
        if(tree->right)
            infix(tree->right);
    }

    void postfix(treeNode<T> *tree){
        if(!tree)
            return;

        if(tree->left)
            postfix(tree->left);
        if(tree->right)
            postfix(tree->right);
        cout<<tree->data;
    }

    void prefix(treeNode<T> *tree){
        if(!tree)
            return;

        cout<<tree->data;
        if(tree->left)
            prefix(tree->left);
        if(tree->right)
            prefix(tree->right);
    }

    void level_order(treeNode<T> *tree){
        Queue<treeNode<T>*> q;
        treeNode<T> *temp = tree;

        while(temp){
            cout<<temp->data;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);

            if(!q.isEmpty())
                temp = q.pop();
            else
                temp = NULL;
        }
    }
};

int precedence(char op){
    if(op == '(' || op == ')' || op == '{' || op == '}')
        return 4;
    else if(op == '^')
        return 3;
    else if(op == '*' || op == '/' || op == '%')
        return 2;
    else if(op == '+' || op == '-')
        return 1;
}

string convertToPostfix(string str){
    int i=0;
    string postfix="";
    stack<char> s;
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
            while(po != '(' && po){
                postfix += po;
                po = s.pop();
            }
        }
        else if(precedence(curr) > precedence( s.peek() ))
            s.push(curr);
        else if(precedence(curr) < precedence( s.peek() )){
            postfix += s.pop();
            continue;                               // pop until prec( curr ) > prec( stack.peek )
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

double arithmetic(double second, char oper, double first){
    switch(oper){
        case '+':
            return first + second;
        case '-':
            return first - second;
        case '*':
            return first * second;
        case '/':
            return second / first;
        case '%':
            return remainder(second, first);
        case '^':
            return pow(first, second);
    }
}

double evaluation(string postfix){
    stack<double> s;
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
    expressionTree<char> et;
    string infix, postfix;
    int choice;

    cout<<"1: Input. \n2: Prefix expression. \n3: Postfix expression. \n4: Infix expression. \n5: Level order expression. \n0: Exit. "<<endl;
    while(choice){
        cout<<"\nEnter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
                cout<<"1: Numeric expression. \n2: Algebraic expression. "<<endl;
                cout<<"Enter your choice: ";
                cin >> choice;

                switch(choice){
                    case 1:{
                        cout<<"Enter infix numeric expression: ";
                        getline(cin, infix);
                        if(infix == "")
                            getline(cin, infix);

                        postfix = convertToPostfix(infix);
                        et.genereteExpTree(postfix);

                        cout<<"Evaluated value: "<<evaluation(postfix)<<endl;
                        break;
                    }
                    case 2:{
                        cout<<"Enter infix algebraic expression: ";
                        getline(cin, infix);
                        if(infix == "")
                            getline(cin, infix);

                        postfix = convertToPostfix(infix);
                        et.genereteExpTree(postfix);
                        break;
                    }
                }
                break;
            }
            case 2:{
                cout<<"Prefix expression: ";
                et.prefix(et.root);
                cout<<endl;
                break;
            }
            case 3:{
                cout<<"Postfix expression: ";
                et.postfix(et.root);
                cout<<endl;
                break;
            }
            case 4:{
                cout<<"Infix expression: ";
                et.infix(et.root);
                cout<<endl;
                break;
            }
            case 5:{
                cout<<"Level order expression: ";
                et.level_order(et.root);
                cout<<endl;
                break;
            }
            case 0:{
                break;
            }
        }
    }

    cout<<"\nProgram ended";
    return 0;
}
