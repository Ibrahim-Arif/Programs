#include <iostream>
using namespace std;

template<class K, class V>
class node{
public:
    //K key;
    V value;
    node<K, V> *left, *right, *parent, *un;
    bool isBlack, isLeftChild;

    node(/*K k, */V v, node<K, V> *p){
        //key = k;
        value = v;
        left  = right = nullptr;
        parent = p;
        isBlack = isLeftChild = false;
    }
};

template<class K, class V>
class redBlackTree{
private:
    node<K, V>* leftRotate(node<K, V> *x, bool for_insert){      // RR
        node<K, V> *y   = x->right,
                              *z   = y->left;

        y->left = x;
        x->right = z;

        y->parent = x->parent;
        x->parent = y;
        if(z){
            z->isLeftChild = false;
            z->parent = x;
        }

        y->isLeftChild = x->isLeftChild;

        if(for_insert){
            y->isBlack = true;

            if(y->left){
                  y->left->isBlack = false;
                  y->left->isLeftChild = true;
            }
             if(y->right){
                    y->right->isBlack = false;
                    y->right->isLeftChild = false;
             }
        }
        return y;
    }
    node<K, V>* rightRotate(node<K, V> *x, bool for_insert){     // LL
        node<K, V> *y   = x->left,
                              *z   = y->right;
        y->right = x;
        x->left = z;

        y->parent = x->parent;
        x->parent = y;
        if(z){
            z->isLeftChild = true;
            z->parent = x;
        }

        y->isLeftChild = x->isLeftChild;

        if(for_insert){
            y->isBlack = true;

            if(y->left){
                  y->left->isBlack = false;
                  y->left->isLeftChild = true;
            }
             if(y->right){
                  y->right->isBlack = false;
                  y->right->isLeftChild = false;
             }
        }
        return y;
    }

    node<K, V>* connect_P_to_GP(node<K, V> *parent){        // it will connect parent with his parent(grand parent)
        node<K, V> *grandParent = parent->parent;

        if(parent->isLeftChild)
            grandParent->left = parent;
        else
            grandParent->right = parent;

        return grandParent;
    }
    node<K, V>* searchUtil(V value, node<K, V> *n){                 // return node to be searched, nullptr is not found
        if(!n)
            return nullptr;

        if(n->value == value)
            return n;

        if(value > n->value)
            return searchUtil(value, n->right);
        if(value < n->value)
            return searchUtil(value, n->left);
    }
    void swapValues(node<K, V> *a, node<K, V> *b){
        int temp = a->value;
        a->value = b->value;
        b->value = temp;
    }

    void fix(node<K, V> *n){                                                             // it will fix after insertion of new node
        node<K, V> *parent, *grandParent, *aunt;
        parent = grandParent = aunt = nullptr;

        while(n->parent && !n->isBlack && !n->parent->isBlack){         // while n->parent exist & n->parent is RED (till root)
            parent = n->parent;
            grandParent = parent->parent;

            if(parent->isLeftChild){                                                // parent is LEFT CHILD
                aunt = grandParent->right;

                if( aunt && !aunt->isBlack ){                                    // aunt is RED
                    parent->isBlack = true;
                    aunt->isBlack = true;
                    grandParent->isBlack = false;
                    n = grandParent;
                }
                else if(!aunt || aunt->isBlack){                                                // aunt is BLACK
                    if(n->isLeftChild){                                                                // LL
                        //cout<<"LL"<<endl;
                        if(grandParent == root)
                            root  = rightRotate(grandParent, true);
                        else{
                            parent = rightRotate(grandParent, true);
                            grandParent = connect_P_to_GP(parent);
                        }
                        n = grandParent;
                    }
                    else{
                         if(grandParent == root){                                                       // LR
                            //cout<<"LR"<<endl;
                            grandParent->left = leftRotate(grandParent->left, true);
                            root = rightRotate(grandParent, true);
                         }
                        else{
                            grandParent->left = leftRotate(grandParent->left, true);
                            parent = rightRotate(grandParent, true);
                            grandParent = connect_P_to_GP(parent);
                        }
                        n = grandParent;
                    }
                }
            }
            else{                                                                                             // parent is RIGHT CHILD
                aunt = grandParent->left;

                if( aunt && !aunt->isBlack ){                                                   // aunt is RED
                    parent->isBlack = true;
                    aunt->isBlack = true;
                    grandParent->isBlack = false;
                    n = grandParent;
                }
                else if(!aunt || aunt->isBlack){
                    if(n->isLeftChild){                                                              // RL
                        //cout<<"RL"<<endl;
                        if(grandParent == root){
                            grandParent->right = rightRotate(grandParent->right, true);
                            root = leftRotate(grandParent, true);
                        }
                        else{
                            grandParent->right = rightRotate(grandParent->right, true);
                            parent = leftRotate(grandParent, true);
                            grandParent = connect_P_to_GP(parent);
                        }
                        n = grandParent;
                    }
                    else{                                                                                  // RR
                        //cout<<"RR"<<endl;
                        if(grandParent == root)
                            root = leftRotate(grandParent, true);
                        else{
                            parent = leftRotate(grandParent, true);
                            grandParent = connect_P_to_GP(parent);
                        }
                        n = grandParent;
                    }
                }
            }
        }
        root->isBlack = true;
    }
    node<K, V>* insertUtil(V value){
        if(!root){
            root = new node<K, V>(value, nullptr);
            root->isBlack = true;
            return nullptr;
        }

        node<K, V> *n = root, *parent;

        while(n){
            parent = n;
            if(value > n->value)
                n = n->right;
            else if(value < n->value)
                n = n->left;
        }

        n = new node<K, V>(value, parent);

        if(value > parent->value)
            parent->right = n;
        else if(value < parent->value){
            parent->left = n;
            n->isLeftChild = true;
        }
        return n;
    }

    node<K, V>* findReplacer(node<K, V> *n){
        if( !n->left && !n->right)                                                 // no children
            return nullptr;

        if(!n->left)                                                                        // no left child
            return n->right;
        else if(!n->right)                                                            // no right child
            return n->left;
                                                                                              // 2 child
        n = n->right;                                                                 // selecting right subtree of deletion node
        while (n && n->left)                                                    // return smallest one from right subtree
            n = n->left;
        return n;
    }
    void deleteNode(node<K, V> *n){
        if(!n)                                                                                                           // if Not found
            return;

        node<K, V> *replacer, *sibling, *parent;
        replacer = sibling = parent = nullptr;
        bool rnBlack;

        parent = n->parent;
        replacer = findReplacer(n);                                                                      // successor of n from RIGHT subtree
        rnBlack = ( (!replacer || replacer->isBlack) && n->isBlack );               // both n & replacer is BLACK


        if( !replacer ){                                                        // 'n' no child
            if(n == root)
                root = nullptr;
            else{
                if(n->isLeftChild)                                            // 'n' is left then sibling is right
                    sibling = parent->right;
                else                                                                 // 'n' is right then sibling is left
                    sibling = parent->left;

                if(rnBlack)
                    fixDoubleBlack(n);                                    // fix double black at 'n'
                else{
                    if(sibling)
                        sibling->isBlack = false;
                }

                if(n->isLeftChild)
                    parent->left = nullptr;
                else
                    parent->right = nullptr;
            }
            delete n;
            return;
        }

        if( !n->left  || !n->right ){                                           // 'n' has 1 child
            if(n == root){
                n->value = replacer->value;
                n->left = n->right = nullptr;
                delete replacer;
            }
            else{
                if(n->isLeftChild)
                    parent->left = replacer;
                else
                    parent->right = replacer;

                replacer->parent = parent;
                delete n;

                if(rnBlack)
                    fixDoubleBlack(replacer);                     // fix double black at replacer
                else
                    replacer->isBlack = true;
            }
            return;
        }

        swapValues(replacer, n);                                        // 'n' has 2 child
        deleteNode(replacer);                                           // after swapping values, delete replacer from its old position.
    }
    void fixDoubleBlack(node<K, V> *n){
        node<K, V> *sibling = nullptr,
                              *parent = n->parent,
                              *grandParent = parent->parent;

        if(n->isLeftChild)
            sibling = parent->right;
        else
            sibling = parent->left;

        if(!sibling)
            fixDoubleBlack(parent);
        else{
            bool oneRedChild = (      (sibling->left   && !sibling->left->isBlack)
                                                     || (sibling->right && !sibling->right->isBlack) );   // at least one child of sibling is RED

            if( !sibling->isBlack ){                                                    // sibling is RED
                parent->isBlack = false;
                sibling->isBlack = true;

                if(sibling->isLeftChild)
                    rightRotate(parent, false);                                    // right rotate(parent)
                else
                    leftRotate(parent, false);                                       // left rotate(parent)

                fixDoubleBlack(n);
            }
            else{
                if(oneRedChild){                                                             // at least one child of sibling is RED
                    if(sibling->left && !sibling->left->isBlack){
                        if(sibling->isLeftChild){                                                     // LL
                            //cout<<"LL"<<endl;
                            sibling->left->isBlack = sibling->isBlack;
                            sibling->isBlack = parent->isBlack;
                            parent = rightRotate(parent, false);
                            grandParent = connect_P_to_GP(parent);
                        }
                        else{                                                                                     // RL
                            //cout<<"RL"<<endl;
                            sibling->left->isBlack = parent->isBlack;
                            parent->right = rightRotate(sibling, false);
                            parent = leftRotate(parent, false);
                            grandParent = connect_P_to_GP(parent);
                        }
                    }
                    else{
                        if(sibling->isLeftChild){                                                       // LR
                            //cout<<"LR"<<endl;
                            sibling->right->isBlack = parent->isBlack;
                            parent->left = leftRotate(sibling, false);
                            parent = rightRotate(parent, false);
                            grandParent = connect_P_to_GP(parent);

                        }
                        else{                                                                                        // RR
                            //cout<<"RR"<<endl;
                            sibling->right->isBlack = sibling->isBlack;
                            sibling->isBlack = parent->isBlack;
                            parent = leftRotate(parent, false);
                            grandParent = connect_P_to_GP(parent);
                        }
                    }
                    parent->isBlack = true;
                }
                else{                                                                                 // sibling's both child is BLACK
                    sibling->isBlack = false;
                    if(parent->isBlack)
                        fixDoubleBlack(parent);
                    else
                        parent->isBlack = true;
                }
            }
        }
    }

    void preTraverseUtil(node<K, V> *n){
        if(n){
            char color      = (n->isBlack) ? 'B' : 'R' ,
                     position = (n->isLeftChild) ? 'L' : 'R' ;
            cout<<"("<<n->value<<" "<<color<<" "<<position<<"), ";
            preTraverseUtil(n->left);
            preTraverseUtil(n->right);
        }
    }

public:
    node<K, V> *root;
    int size;
    redBlackTree(){
        root = nullptr;
        size = 0;
    }

    void insert(V value){
        node<K, V> *n = insertUtil(value);
        if(n)
            fix(n);
    }
    void Delete(V value){
         node<K, V> *n = searchUtil(value, root);
         deleteNode(n);
    }
    void search(V value){
        node<K, V> *n = searchUtil(value, root);
        if(n)
            cout<<n->value<<" found!"<<endl;
        else
            cout<<"Not found!"<<endl;
    }
    void preTraverse(){
        preTraverseUtil(root);
    }
};

int main()
{
    redBlackTree<int, int> rb;
    int choice, ele;

    while(choice){
        cin >> choice;

        switch(choice){
            case 1:{
                cin >> ele;
                rb.insert(ele);
                break;
            }
            case 2:{
                cin >> ele;
                rb.Delete(ele);
                break;
            }
            case 3:{
                cin >> ele;
                rb.search(ele);
                break;
            }
            case 4:{
                cout<<"elements: ";
                rb.preTraverse();
                cout<<endl<<endl;
                break;
            }
            case 0:{
                break;
            }
            default:{
                cout<<"wrong input"<<endl;
                break;
            }
        }
    }

    /*for(int i=10; i<=200; i+=10)
        rb.insert(i);*/
    cout<<"\nEnded"<<endl;
    return 0;
}
