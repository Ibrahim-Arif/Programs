#include <iostream>
using namespace std;

template<class T>
class node{
public:
    T data;
    node<T> *left;
    node<T> *right;

    node(){}
    node(T d){
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

template<class T>
class linked_list{
public:
    node<T> *head, *tail;
    linked_list(){
        head = nullptr;
        tail = nullptr;
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
            n->left = temp;
        }
    void display(){
        node<T> *h = head;
        cout<< "List elements are: " << endl;
        while(h){
            cout << h->data << ", ";
            h = h->right;
        }
        cout<<endl;
    }
    void update_tail(){
        node<T> *h = head;
        while(h){
            tail = h;
            h = h->right;
        }
    }
};

node<int>* sort_list(node<int> *head){
    linked_list<int> *even = new linked_list<int>;
    linked_list<int> odd;

    while(head){
        if(head->data%2 == 0)
            even->append(head->data);
        else
            odd.append(head->data);

        head = head->right;
    }
    even->update_tail();
    even->tail->right = odd.head;
    return even->head;
}

int main()
{
    int choice;
    int ele;
    linked_list<int> list;

    cout<<"1: Insert into list. \n2: Sort list. \n3: Display. \n0: Exit." << endl;
    while(choice){
        cout<<"\nEnter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
                cout<<"Enter an element: ";
                cin >> ele;
                list.append(ele);
                break;
            }
            case 2:{
                list.head = sort_list(list.head);
                break;
            }
            case 3:{
                list.display();
                break;
            }
            case 0:{
                break;
            }
            default:{
                cout<<"Wrong input!"<<endl;
                break;
            }
        }
    }
    return 0;
}
