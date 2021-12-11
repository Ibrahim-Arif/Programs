#include <iostream>                 // https://www.hackerrank.com/challenges/tree-top-view/problem
#include <queue>
using namespace std;
template<class T>
class node{
public:
    T data;
    node<T> *left, *right;
    node(){}
    node(T ele){
        data = ele;
        left = right = nullptr;
    }
};

template<class T>
class tree{
public:
    node<T> *root;
    tree(){
        root = nullptr;
    }

    node<T>* insert(node<T> *curr, node<T> *ele){
        if(curr == nullptr)                     return ele;
        if(ele->data < curr->data)      curr->left = insert(curr->left, ele);
        else                                           curr->right = insert(curr->right, ele);
        return curr;
    }
    void in_order(node<T> *curr){
        if(root == NULL){
            printf("Tree is empty!");
            return;
        }
        cout<<curr->data << ", " ;
        if(curr->left)      in_order(curr->left);
        if(curr->right)    in_order(curr->right);
    }
    void level_order(node<T> *curr){
        queue<node<T>*> q;
        node<T> *temp = curr;

        while(temp){
            cout<<temp->data<<", ";
            if(temp->left)          q.push(temp->left);
            if(temp->right)        q.push(temp->right);

            temp = q.front();
            q.pop();
        }
    }

    void topView(node<T> *curr, char ch){
        if(curr == root){
            if(curr->left)       topView(curr->left, 'l');
            cout<<curr->data<<", ";
            if(curr->right)     return topView(curr->right, 'r');
        }
        if(curr->left && ch=='l')       topView(curr->left,'l');
        cout<<curr->data<<", ";
        if(curr->right && ch=='r')     topView(curr->right, 'r');
    }
};

int main()
{
    int choice, ele;
    tree<int> tree;
    node<int> *n;

    cout<<"1: Insert into tree. \n2: Pre-order display. \n3: Top view. \n4: Level-order display. \n0: Exit." <<endl;
    while(choice){
        cout<<"\nEnter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
                cout<<"Enter data: ";
                cin >> ele;
                n = new node<int>(ele);

                if( !tree.root )    tree.root = n;
                else                   tree.insert(tree.root, n);
                break;
            }
            case 2:{
                tree.in_order(tree.root);
                break;
            }
            case 3:{
                cout<<"Top view: " <<endl;
                tree.topView(tree.root, ' ');
                break;
            }
            case 4:{
                cout<<"Level order display: "<<endl;
                tree.level_order(tree.root);
                break;
            }
            case 0:{
                break;
            }
        }
    }
}
