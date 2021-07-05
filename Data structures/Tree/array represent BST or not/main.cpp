#include <iostream>                     //https://www.geeksforgeeks.org/check-given-array-of-size-n-can-represent-bst-of-n-levels-or-not/
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
        if(curr->left)       in_order(curr->left);
        if(curr->right)    in_order(curr->right);
    }
};

int index=0;
bool tree_vs_array(node<int> *root, int *arr){

    if(root->data != arr[index++]){
        //cout<<"array: "<<arr[index-1]<<" tree: "<<root->data<<endl;
        return false;
    }
    if(root->left)      return tree_vs_array(root->left, arr);
    if(root->right)    return tree_vs_array(root->right, arr);

    return true;
}

int main()
{
    int choice, i=0;
    int ele=1;
    int *arr = new int[10];
    tree<int> tree;
    node<int> *n;

    cout<<"Enter elements for array: ";
    while(ele > 0){                                         //enter any negative number to break loop
        cin >> ele;
        arr[i++] = ele;
    }

    n= new node<int>(arr[0]);
    tree.root = n;
    for(int j=1; j<i-1; j++){
        n = new node<int>( arr[j] );
        tree.insert(tree.root, n);
    }

    if( tree_vs_array(tree.root, arr) )
        cout<<"BST available: Yes"<<endl;
    else
        cout<<"BST available: No"<<endl;
    return 0;
}
