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
        head = tail = nullptr;
    }

    void    append(T ele);
    void    add_to_begin(T ele);
    void    add_after(T index, T ele);
    T         delete_first();
    T         _delete(T ele);
    void    display();
    void    reverse();
    void    swap(T x, T y);
};

    template<class T>
    void linked_list<T>:: append(T ele){
            node<T> *n = new node<T>(ele);
            if(!head){
                head = n;
                tail = n;
                tail->right = head;
                head->left = tail;
                return;
            }
            tail->right = n;
            n->left = tail;
            tail = n;
            tail->right = head;
            head->left = tail;
        }

    template<class T>
    void linked_list<T>:: add_to_begin(T ele){
        node<T> *n = new node<T>(ele);
        if(!head){
            head = n;
            tail = n;
            tail->right = head;
            head->left = tail;
            return;
        }
        n->right = head;
        head->left = n;
        head = n;
        head->left = tail;
        tail->right = head;
    }

    template<class T>
    void linked_list<T>:: add_after(T index, T ele){
        node<T> *n = new node<T>(ele);
        node<T> *temp = head;

        do{
            temp = temp->right;
        } while(temp->data != index && temp != head );

        if(temp == tail){
            tail = n;
        }

        n->right = temp->right;
        temp->right->left = n;
        temp->right = n;
        n->left = temp;
    }

    template<class T>
    T linked_list<T>:: _delete(T ele){
        node<T> *curr = head;
        while(curr->data != ele)
            curr = curr->right;

        if(curr == tail)
            tail = tail->left;
        if(curr == head)
            head = head->right;

        if(curr->left)
            curr->left->right = curr->right;

        if(curr->right)
            curr->right->left = curr->left;

        curr->left = curr->right = nullptr;
        return curr->data;
    }

    template<class T>
    void linked_list<T>:: display(){
        node<T> *temp = head;
        cout<< "List elements are: " << endl;
       do{
            cout << temp->data << ", ";
            temp = temp->right;
        }while(temp != tail->right);
        cout<<endl;
    }

int main()
{
     int choice, loc1;
     int ele;                                               //change data type of elements, list to convert into any data type double list..
     linked_list<int> listt;
     cout << "1: Append \n2: Add at begin \n3: Add After \n4: Delete first \n5: Delete specified \n6: Display \n0: Exit" << endl;
     do{
            cout << "\nEnter your choice: ";
            cin >> choice;
            switch(choice){
                case 1:{
                    cout<< "Enter an element: ";
                    cin >> ele;
                    listt.append(ele);
                    break;
                }
                case 2:{
                    cout<< "Enter an element: ";
                    cin >> ele;
                    listt.add_to_begin(ele);
                    break;
                }
                case 3:{
                    cout << "Enter index & element: ";
                    cin >> loc1;
                    cin >> ele;
                    listt.add_after(loc1, ele);
                    break;
                }
                case 5:{
                    cout << "Enter element to delete: ";
                    cin >> ele;
                    ele = listt._delete(ele);
                    cout <<  ele << " deleted successfully!" << endl;
                    break;
                }
                case 6:{
                    listt.display();
                    break;
                }
                case 0:{
                    break;
                }
                default:{
                    cout << "Wrong Input!" <<endl;
                }
            }
    }while(choice != 0);
    return 0;
}
