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
            return nullptr;
        n = head;
        head = head->link;
        size--;
        return n->data;
    }
    T peek(){
        if( isEmpty() )
            return nullptr;
        return head->data;
    }
    bool isEmpty(){
        return (!size) ? true : false;
    }
};

treeNode<char>* genereteExpTree(string expression){
    stack<treeNode<char>*> nodeS;
    char curr = expression[0];
    int i=0;

    while(expression[i] != '\0'){
        curr = expression[i++];

        if(isspace(curr))
            continue;

        treeNode<char> *temp = new treeNode<char>(curr);

        if(isdigit(curr) || isalpha(curr)){
            nodeS.push(temp);

        }else{
            temp->right = nodeS.pop();
            temp->left = nodeS.pop();

            nodeS.push(temp);
        }
    }
    return nodeS.pop();
}

void triversal(treeNode<char> *tree){
    if(!tree)
        return;

    //cout<<tree->data;                 // prefix

    if(tree->left)
        triversal(tree->left);

    cout<<tree->data;                   // infix

    if(tree->right)
        triversal(tree->right);

    //cout<<tree->data;                 // postfix
}

int main()                                                      // input must be in POSTFIX
{
    //string postfix = "a b + e f g * * - ";
    string postfix = "13  8 *2 /+7 +1-";

    treeNode<char> *tree = genereteExpTree(postfix);

    triversal(tree);

    cout<<"\n\nEnded";
    return 0;
}
