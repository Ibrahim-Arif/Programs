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
    int length;
    tree(){
        root = nullptr;
        length = 0;
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
class toBBST{
public:
    T *arr;
    int i;
    toBBST(int cap){
        arr = new T[cap];
        i=0;
    }

    T* BST_to_ARR(node<T> *curr, T *arr){
        if(curr->left)       BST_to_ARR(curr->left, arr);
        arr[i++] = curr->data;
        if(curr->right)    BST_to_ARR(curr->right, arr);

        return arr;
    }
    node<T>* ARR_to_BBST(T *arr, int start, int last){
        if(start > last)    return nullptr;

        int mid = (start+last) / 2;
        node<T> *root = new node<T>( arr[mid] );

        root->left = ARR_to_BBST(arr, start, mid-1);
        root->right = ARR_to_BBST(arr, mid+1, last);
        return root;
    }
};

int main()
{
    int choice=1;
    int ele;
    tree<int> tree;
    node<int> *n;

    cout << "1: Insert into BST. \n2: Convet into Balanced BST. \n3: Display BBST. "<<endl;
    while(choice){
        cout<<"\nEnter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
                cout<<"Enter an element: ";
                cin >> ele;
                n = new node<int>(ele);            //  | => change

                if( !tree.root )        tree.root = n;
                else                       tree.insert(tree.root, n);
                tree.length++;
                break;
            }
            case 2:{
                toBBST<int> bbst(tree.length);
                int *p = bbst.BST_to_ARR(tree.root, bbst.arr);
                n = bbst.ARR_to_BBST(p, 0, tree.length-1);
                tree.pre_order(n);
                break;
            }
            case 3:{
                tree.pre_order(tree.root);
                cout<<endl;
                break;
            }
            case 0:{
                break;
            }
        }
    }
    return 0;
}
