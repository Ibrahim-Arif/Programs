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
    int count;
    tree(){
        root = nullptr;
        count =0;
    }

    node<T>* insert(node<T> *curr, node<T> *ele){
        if(curr == nullptr)                     return ele;
        if(ele->data.length() < curr->data.length())      curr->left = insert(curr->left, ele);
        else                                                                        curr->right = insert(curr->right, ele);
        return curr;
    }
    void find(node<T> *curr, T srch){
        if(curr->left)       find(curr->left, srch);

        if(curr->data.length() >= srch.length()){                           // if searching substring must be smaller than current node
            if( !(curr->data.compare(0, srch.length(), srch)) )       // compare current node elements from index 0 - substring length  with substr then count++
                count++;
        }
        if(curr->right)    find(curr->right, srch);
    }
};

int main()
{
    string que, ele;
    node<string> *n;
    tree<string> tree;

    int total;
    cin >> total;
    while(total){
        cin >> que;
        cin >> ele;

        if(que == "add"){
            n = new node<string>(ele);
            if( !tree.root )    tree.root = n;
            else                    tree.insert(tree.root, n);
        }
        if(que == "find"){
            tree.find(tree.root, ele);
            cout<<tree.count<<endl;
            tree.count = 0;
        }
        total--;
    }
    return 0;
}
