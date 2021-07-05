#include <iostream>
using namespace std;

template<class T>
class node{
public:
    T data;
    int priority;
    node<T> *left;
    node<T> *right;

    node(){}
    node(T d, int p){
        data = d;
        priority = p;
        left = nullptr;
        right = nullptr;
    }
};

template<class T>
class priority_Q{
public:
    node<T> *rear, *front;
    priority_Q(){
        rear = front = nullptr;
    }
    ~priority_Q(){
        clear_();
        cout<<"Destructor called!"<<endl;
    }

    void enQ(T ele, int prio){
        node<T> *n = new node<T>(ele, prio);
        if(!rear){
            rear = front = n;
            return;
        }
        n->right = rear;
        rear->left = n;
        rear = n;

        adjust();
    }

    T dQ(){
        T value;
        node<T> *temp = front;

        if(temp)
            value = temp->data;
        else
            return "-1";

        if(front == rear){
            delete temp;
            front = rear = nullptr;

            return value;
        }

        front = front->left;
        front->right = nullptr;
        delete temp;

        return value;
    }

    T front_name(){
        if(!isEmpty())
            return front->data;
        else
            return "";
    }

    int front_priority(){
        if(!isEmpty())
            return front->priority;
        else
            return -1;
    }

    void update_priority(T patient, int new_priority){
        delete_(patient, new_priority);
        enQ(patient, new_priority);
    }

    void clear_(){
        node<T> *temp = rear, *next;
        while(temp){
            next = temp->right;
            delete temp;
            temp = next;
        }
        front = nullptr;
        rear = nullptr;
    }

    void adjust(){
        node<T> *temp = rear, *next;
        T hold;
        int temp_prio;

        while(temp){
            next = temp->right;
            if(!next)
                return;

            if(temp->priority < next->priority){
                hold = temp->data;
                temp->data = next->data;
                next->data = hold;

                temp_prio = temp->priority;
                temp->priority = next->priority;
                next->priority = temp_prio;
            }

            temp = temp->right;
        }
    }

    void delete_(T ele, int pri){
        node<T> *curr = rear;

        while(curr->data != ele && curr->priority != pri && curr)
            curr = curr->right;

        if(curr->left)
            curr->left->right = curr->right;
        else{
            rear = curr->right;
            rear->left = nullptr;
        }
        if(curr->right)
            curr->right->left = curr->left;
        else{
            front = curr->left;
            front->right = nullptr;
        }
        curr->left = curr->right = nullptr;
        delete curr;
    }

    bool isEmpty(){
        return (front == nullptr);
    }
};



int main()
{
    priority_Q<string> pq;
    string ele;
    int prio, choice;

    cout<<"1: Enqueue. \n2: Dequeue. \n3: front_name. \n4: front_priority. \n5: update priority. \n6: clear. \n0: Exit."<<endl;
    while(choice){
        cout<<"\nEnter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
                cout<<"Enter Patient name, priority: ";
                cin >> ele;
                cin >> prio;
                pq.enQ(ele, prio);
                break;
            }
            case 2:{
                ele = pq.dQ();
                if(ele != "-1")
                    cout<<"Urgent patient: "<<ele<<endl;
                else
                    cout<<"Queue underflow!"<<endl;
                break;
            }
            case 3:{
                cout<<"Urgent patient name: "<<pq.front_name()<<endl;
                break;
            }
            case 4:{
                cout<<"Urgent patient priority: "<<pq.front_priority()<<endl;
                break;
            }
            case 5:{
                cout<<"Enter patient name, new priority: ";
                cin >> ele;
                cin >> prio;
                pq.update_priority(ele, prio);
                cout<<"Priority updated successfully!"<<endl;
                break;
            }
            case 6:{
                pq.clear_();
                cout<<"All records cleared successfully! "<<endl;
                break;
            }
            case 0:{
                break;
            }
            default:{
                cout<<"Wrong choice!"<<endl;
                break;
            }
        }
    }
    return 0;
}
