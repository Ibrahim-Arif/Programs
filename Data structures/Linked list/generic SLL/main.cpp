#include <iostream>
using namespace std;

template<class T>
class node{
public:
    T data;
    node *link;
    node(){}
    node(T ele){
        data = ele;
        link = nullptr;
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
            tail = n;
            return;
        }
        tail->link = n;
        tail = n;
    }
    void add_to_begin(T ele){
        node<T> *n = new node<T>(ele);
        if(!head){
            head = n;
            return;
        }
        n->link = head;
        head = n;
    }
    void add_after(int index, T ele){
        node<T> *n = new node<T>(ele);
        node<T> *temp = head;
        for(int i=1; i<index; i++){
            temp = temp->link;
        }
        n->link = temp->link;
        temp->link = n;
    }
    T delete_first(){
        node<T> *temp = head;
        head = head->link;
        return temp->data;
    }
    T delete_specified(T ele){
        node<T> *curr = head, *previous;
        while(curr->data != ele){
            previous = curr;
            curr = curr->link;
        }
        if(curr == tail)
            tail = previous;

        previous->link = curr->link;
        return curr->data;
    }
    void display(){
        node<T> *temp = head;
        cout<< "List elements are: " << endl;
        while(temp){
            cout << temp->data << ", ";
            temp = temp->link;
        }
        cout<<endl;
    }
    int length(){
        int count =0;
        node<T> *temp = head;
        while(temp){
            count++;
            temp = temp->link;
        }
        return count;
    }
    void reverse(){
        int i=0, j, len = length();
        T temp;
        node<T> *p = head, *q = head;
        j = len-1;
        while(i<j){
            for(int k=0; k<j; k++)
                q = q->link;

            temp = p->data;
            p->data = q->data;
            q->data = temp;

            i++;
            j--;
            p = p->link;
            q=head;
        }
    }
    void swap(T first, T second){
        node<T> *currF = head,
                         *prevF = nullptr,
                         *currS  = head,
                         *prevS = nullptr,
                         *temp  = nullptr;

        if(first == second){
            cout<<"Masti kr reya, baaz aja!" << endl;
            return;
        }

        while(currF && currF->data != first){
            prevF = currF;
            currF = currF->link;
        }
        while(currS && currS->data != second){
            prevS = currS;
            currS = currS->link;
        }

        if(!currF || !currS){
            cout<<"Element not found!" <<endl;
            return;
        }

        if(prevF != NULL)
            prevF->link = currS;
        else
            head = currS;

        if(prevS != NULL)
            prevS->link = currF;
        else
            head = currF;

        temp = currS->link;
        currS->link = currF->link;
        currF->link = temp;
    }
};

int main()
{
    int choice, loc1;
    int ele, ele2;
    linked_list<int> listt;
    printf("1: Append \n2: Add at begin \n3: Add After \n4: Delete first \n5: Delete specified \n6: Display \n7: Length \n8: Reverse \n9: Swap \n0: Exit");
    do{
            printf("\nEnter your choice: ");
            scanf("%d",&choice);
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
