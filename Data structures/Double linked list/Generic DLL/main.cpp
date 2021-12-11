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
    node<T> *head;
    linked_list(){
        head = nullptr;
    }

    void    append(T ele);
    void    add_to_begin(T ele);
    void    add_after(int index, T ele);
    T         delete_first();
    T         delete_specified(T ele);
    void    display();
    int       length();
    void    reverse();
    void    swap(T x, T y);
};

    template<class T>
    void linked_list<T>:: append(T ele){
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

    template<class T>
    void linked_list<T>:: add_to_begin(T ele){
        node<T> *n = new node<T>(ele);
        if(!head){
            head = n;
            return;
        }
        n->right = head;
        head->left = n;
        head = n;
    }

    template<class T>
    void linked_list<T>:: add_after(int index, T ele){
        node<T> *n = new node<T>(ele);
        node<T> *temp = head;
        for(int i=1; i<index; i++){
            temp = temp->right;
        }
        n->right = temp->right;
        temp->right->left = n;
        temp->right = n;
        n->left = temp;
    }

    template<class T>
    T linked_list<T>:: delete_first(){
        node<T> *temp = head;
        head = head->right;
        head->left = nullptr;
        return temp->data;
    }

    template<class T>
    T linked_list<T>:: delete_specified(T ele){
        node<T> *curr = head;
        while(curr->data != ele){
            curr = curr->right;
        }
        if(curr->left)
            curr->left->right = curr->right;
        else{
            head = curr->right;
            head->left = nullptr;
        }
        if(curr->right)
            curr->right->left = curr->left;
        curr->left = curr->right = nullptr;
        return curr->data;
    }

    template<class T>
    void linked_list<T>:: display(){
        node<T> *temp = head;
        cout<< "List elements are: " << endl;
        while(temp){
            cout << temp->data << ", ";
            temp = temp->right;
        }
        cout<<endl;
    }

    template<class T>
    int linked_list<T>:: length(){
        int count =0;
        node<T> *temp = head;
        while(temp){
            count++;
            temp = temp->right;
        }
        return count;
    }

    template<class T>
    void linked_list<T>:: reverse(){
        node<T> *curr = head, *tail, *temp;
        while(curr->right)
            curr = curr->right;
        tail = curr;

        curr = head;
        while(curr){
            temp = curr->right;
            curr->right = curr->left;
            curr->left = temp;

            curr = curr->left;
        }
        head = tail;
    }

    template<class T>
    void linked_list<T>:: swap(T x, T y){
        node<T> *first=head, *second=head, *prevF, *prevS, *nextF, *nextS;
        int flag=0;
        if(x == y){
            cout << "Masti kr reya, baz aja!" << endl;
            return;
        }
        while(first && first->data != x)
            first = first->right;
        while(second && second->data != y)
            second = second->right;

        if(!first || !second){
            printf("Not found!");
            return;
        }
        prevF = first->left;
        prevS = second->left;
        nextF = first->right;
        nextS = second->right;

        if(nextF->data == y || prevS->data ==x)
            flag =1;

        if(prevF)
            prevF->right = second;
        else
            head = second;

        prevS->right = first;
        first->right = nextS;

        if(flag == 0){
            second->right = nextF;
            second->left = prevF;
            nextF->left = second;
            first->left = prevS;
        }else{
            second->right = first;
            second->left = prevF;
            nextF->left = prevF;
            first->left = second;
        }
        if(first->right != NULL)
            first->right->left = first;
    }

int main()
{
     int choice, loc1;
     int ele, ele2;                                         //change data type of elements, list to convert into any data type double list..
     linked_list<int> listt;
     cout << "1: Append \n2: Add at begin \n3: Add After \n4: Delete first \n5: Delete specified "
                "\n6: Display \n7: Length \n8: Reverse \n9: Swap \n0: Exit" << endl;
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
                case 4:{
                    ele = listt.delete_first();
                    cout <<  ele << " deleted successfully!" << endl;
                    break;
                }
                case 5:{
                    cout << "Enter element to delete: ";
                    cin >> ele;
                    ele = listt.delete_specified(ele);
                    cout <<  ele << " deleted successfully!" << endl;
                    break;
                }
                case 6:{
                    listt.display();
                    break;
                }
                case 7:{
                    cout<<"length: " << listt.length() <<endl;
                    break;
                }
                case 8:{
                    listt.reverse();
                    break;
                }
                case 9:{
                    cout << "Enter two elements: ";
                    cin >> ele;
                    cin >> ele2;
                    listt.swap(ele, ele2);
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
