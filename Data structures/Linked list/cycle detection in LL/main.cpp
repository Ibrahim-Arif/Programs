#include <iostream>                         //https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/problem
#include <vector>
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
    node<T> *head, *arr[10];
    int i=0;

    linked_list(){
        head = nullptr;
    }

    void append(T ele){
        node<T> *n = new node<T>(ele);
        arr[i++] = n;

        if(!head){
            head = n;
            return;
        }
        node<T> *temp = head;
        while(temp->link){
            temp = temp->link;
        }
        temp->link = n;
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

    int cycle_detector(){
        node<T> *curr = head;
        i=0;

        while(curr){
            for(int j=0; j<i; j++){
                if(curr == arr[j])
                    return 1;
            }
            i++;
            curr = curr->link;
        }
        return 0;
    }
    int hasCycle(){                             //  this function is from hacker-rank solution (if there is a cycle fast & slow moving pointer will meet somehow)
        node<int> *fast, *slow;
        fast = slow = head;

        while(fast && fast->link){
            slow = slow->link;
            fast = fast->link->link;

            if(fast  == slow)
                return 1;
        }
        return 0;
    }
};

int main()
{
    linked_list<int> list;

    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);
    list.append(7);

    list.display();

    node<int> *temp = list.head;        //manually creating a cycle for testing
    while(temp->link)
        temp = temp->link;
    temp->link = list.head->link;

    cout << "Cycle detection status: " << list.hasCycle() << endl;
    cout << "Cycle detection status: " << list.cycle_detector() << endl;

    return 0;
}
