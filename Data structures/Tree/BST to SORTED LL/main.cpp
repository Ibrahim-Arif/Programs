#include <iostream>
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
    void pre_order(node<T> *curr){
        if(root == NULL){
            printf("Tree is empty!");
            return;
        }
        cout<<curr->data << ", " ;
        if(curr->left)       pre_order(curr->left);
        if(curr->right)    pre_order(curr->right);
    }
};

template<class T>
class toSLL{
public:
    node<T> *head;
    toSLL(){
        head = nullptr;
    }

    void BST_to_SLL(node<T> *curr ){
        if(curr->left)          BST_to_SLL(curr->left);
        append(curr->data);
        if(curr->right)        BST_to_SLL(curr->right);
    }
    void append(T ele){
        node<T> *n = new node<T>(ele);
        if(!head){
            head = n;
            return;
        }
        node<T> *temp = head;
        while(temp->right){
            temp = temp->right;
        }
        temp->right = n;
    }
    void display(){
        node<T> *temp = head;
        if(!temp)   return;
        cout<< "List elements are: " << endl;
        while(temp){
            cout << temp->data << ", ";
            temp = temp->right;
        }
        cout<<endl;
    }
};

int main()
{
    int choice;
    int ele;
    tree<int> tree;
    node<int> *n;
    toSLL<int> sll;

    cout<<"1: Insert into BST. \n2: In-order BST. \n3: Convert into Sorted list. \n4: Display list. \n0: Exit"<<endl;
    while(choice){
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:{
                cout<< "Enter data: ";
                cin >> ele;
                n = new node<int>(ele);

                if(!tree.root)      tree.root = n;
                else                   tree.insert(tree.root, n);
                break;
            }
            case 2:{
                cout<<"Tree elements: "<<endl;
                tree.pre_order(tree.root);
                cout<<endl;
                break;
            }
            case 3:{
                sll.BST_to_SLL(tree.root);
                cout<<"Sorted list generated successfully!"<<endl;
                break;
            }
            case 4:{
                sll.display();
                break;
            }
            case 0:{
                break;
            }
            default:{
                cout<<"wrong input!"<<endl;
                break;
            }
        }
    }
    return 0;
}
