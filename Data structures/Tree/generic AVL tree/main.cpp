#include <iostream>
using namespace std;

template<class T>
class node{
public:
    T data;
    int height;
    node<T> *left, *right, *parent;
    node(){}
    node(T d, node<T> *p){
        data = d;
        parent = p;
        height = 1;
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

    T                    max                        (T a, T b){
        return (a>b) ? a : b;
    }
    T                    height                    (node<T> *p){
        if( !p )                    return 0;
        else                       return p->height;
    }
    int                   balanceFactor     (node<T> *p){
        if(p ==  NULL)      return 0;
        else                       return( height(p->left) - height(p->right) );
    }
    node<T>*     leftRotate              (node<T> *x){
        //cout<<"left: "<<x->data<<endl;
        node<T> *y   = x->right;
        node<T> *z   = y->left;
        y->left = x;
        x->right = z;

        y->parent = x->parent;
        x->parent = y;
        if(z)     z->parent = x;

        x->height = 1+ max( height(x->left), height(x->right) );
        y->height = 1+ max( height(y->left), height(y->right) );
        return y;
}
    node<T>*     rightRotate           (node<T> *x){
        //cout<<"right: "<<x->data<<endl;
        node<T> *y   = x->left;
        node<T> *z   = y->right;
        y->right = x;
        x->left = z;

        y->parent = x->parent;
        x->parent = y;
        if(z)   z->parent = x;

        x->height = 1+ max( height(x->left), height(x->right) );
        y->height = 1+ max( height(y->left), height(y->right) );
        return y;
}
    void                preOrder              (node<T> *r){
        if(r){
            cout<< r->data << ", ";
            preOrder( r->left );
            preOrder( r->right );
        }
}
    int                   count                     (node<T> *p){
        int c = 1;
        if(!p)   return 0;
        else{
            c += count(p->left);
            c += count(p->right);
            return c;
        }
    }
    node<T>*     insert                     (node<T> *p, T value){
        node<T> *par, *n;
        if( !p )
            return new node<T>(value, nullptr);

        while(p){
            par = p;
            if(value > p->data)                 p = p->right;
            else if(value < p->data)        p = p->left;
        }
        n = new node<T>(value, par);
        if(value > par->data)                 par->right = n;
        else if(value < par->data)        par->left = n;
        else                                             return root;

        p =n->parent;
        while(p){
            p->height   = 1+ max( height(p->left), height(p->right) );
            int balance = balanceFactor(p);

            //LL
            if(balance >1 && value < p->left->data){
                p = rightRotate(p);
                if(p->parent){
                    if(p->data > p->parent->data)    p->parent->right = p;
                    else                                                p->parent->left    = p;
                }
            }
            //RR
            if(balance < -1 && value > p->right->data){
                p = leftRotate(p);
                if(p->parent){
                    if(p->data > p->parent->data)    p->parent->right = p;
                    else                                                p->parent->left    = p;
                }
            }
            //LR
            if(balance > 1 && value > p->left->data){
                p->left = leftRotate(p->left);
                p = rightRotate(p);
                if(p->parent){
                    if(p->data > p->parent->data)    p->parent->right = p;
                    else                                                p->parent->left    = p;
                }
            }
            //RL
            if(balance < -1 && value < p->right->data){
                p->right = rightRotate(p->right);
                p = leftRotate(p);
                if(p->parent){
                    if(p->data > p->parent->data)    p->parent->right = p;
                    else                                                p->parent->left    = p;
                }
            }
            if(!p->parent)       break;
            p = p->parent;
        }
        return p;
    }
    T                    search                   (node<T> *p, T value){
        if(!p)                                     return -1;

        if(value == p->data)          return p->data;
        else if(value > p->data)    search(p->right, value);
        else                                     search(p->left, value);
    }
    node<T>*     minValueNode    (node<T> *n) {
          node<T> *curr = n;
          while (curr && curr->left != nullptr)
                curr = curr->left;
          return curr;
    }
    node<T>*     deleteNode         (node<T> *root, T key){
        node<T> *temp;
        if (!root)                    return root;

        if (key < root->data)               root->left = deleteNode(root->left, key);           // finding node to be deleted
        else if (key > root->data)      root->right = deleteNode(root->right, key);

        else {
            if (!root->left) {                                                                                        // If the node is with only one child or no child
                temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right) {
                temp = root->left;
                delete root;
                return temp;
            }
            temp = minValueNode(root->right);                                                                    // If the node has two children
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }
};


int main()
{
    int choice;
    int ele;                            //  | =>  change these two data types to convert tree...
    tree<int> tree;               //  | =>

    cout << "1: Insert \n2: Delete \n3: Search \n4: Total nodes \n5: Pre-order display \n0: Exit" << endl;;
    while(choice != 0){
        cout<< "\nEnter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
                cout << "Enter data: ";
                cin >> ele;
                tree.root = tree.insert(tree.root, ele);
                break;
            }
            case 2:{
                cout << "Enter element to delete: ";
                cin >> ele;
                tree.deleteNode(tree.root, ele);
                cout << ele << " deleted successfully!"<<endl;
                break;
            }
            case 3:{
                cout << "Enter element: ";
                cin >> ele;
                ele = tree.search(tree.root, ele);
                if(ele != -1)   cout << "Element found: " << ele << endl;
                else              cout << "Element not found!" <<endl;;
                break;
            }
            case 4:{
                cout<< "total nodes: " << tree.count(tree.root) <<endl;
                break;
            }
            case 5:{
                cout << "Elements in Pre-Order pattern: " <<endl;
                tree.preOrder(tree.root);
                cout << endl;
                break;
            }
            case 0:{
                break;
            }
            default:{
                printf("wrong input!");
            }
        }
    }
    return 0;
}
