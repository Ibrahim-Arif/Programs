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
        if(curr->left)       pre_order(curr->left);
        cout<<curr->data << ", " ;
        if(curr->right)    pre_order(curr->right);
    }
    node<T>* minValueNode(node<T> *n) {
          node<T> *current = n;
          while (current && current->left != NULL)
                current = current->left;
          return current;
    }
    node<T>* deleteNode(node<T> *r, T key){
        if (r == NULL)
            return r;

        if (key < r->data)
            r->left = deleteNode(r->left, key);                          // finding node to be deleted
        else if (key > r->data)
            r->right = deleteNode(r->right, key);
        else {
            if (r->left == NULL) {                                                                                        // If the node is with only one child or no child
                node<T> *temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL) {
                node<T> *temp = r->left;
                delete r;
                return temp;
            }
            node<T> *temp = minValueNode(r->right);                                                                    // If the node has two children
            r->data = temp->data;
            r->right = deleteNode(r->right, temp->data);
        }
        return r;
    }
    node<T>* search(node<T> *curr, T ele){
        if(curr == NULL || curr->data == ele)       return curr;
        else if(ele > curr->data)                            search(curr->right, ele);
        else if(ele < curr->data)                            search(curr->left, ele);
    }
};

int main()
{
    int choice=1;
    int ele;                                 //  |
    tree<int> tree;                    //  | => change these four data type to convert tree.
    node<int> *n;                     //  |

    cout<< "1: Insert \n2: Delete \n3: Display \n4: Search \n0: Exit"<< endl;
    while(choice != 0){
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:{
                cout<<"Enter data: " ;
                cin >> ele;
                n = new node<int>(ele);     //  | => change

                if( !tree.root )        tree.root = n;
                else                       tree.insert(tree.root, n);
                break;
            }
            case 2:{                                        //delete not working when only one child..
                cout << "Enter element: " ;
                cin >> ele;
                tree.deleteNode(tree.root, ele);
                cout<< ele << " deleted successfully!"<<endl;
                break;
            }
            case 3:{
                cout<<"Tree element in Pre-order: " << endl;
                tree.pre_order(tree.root);
                cout<< endl;
                break;
            }
            case 4:{
                cout << "Enter element: " ;
                cin >> ele;
                n = tree.search(tree.root, ele);
                if(n)   cout<<n->data << " Found!" <<endl;
                else  cout<<"Not found! " <<endl;
                break;
            }
            case 0:{
                break;
            }
            default:{
                printf("wrong input!");
                break;
            }
        }
    }
    return 0;
}
