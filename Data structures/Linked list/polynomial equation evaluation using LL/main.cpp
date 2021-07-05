#include <iostream>
using namespace std;

class node{
public:
    signed coef, x, y, z;
    node *link;
    node(){}
    node(signed c, int xx, int yy, int zz){
        coef = c;
        x = xx;
        y = yy;
        z = zz;
        link = nullptr;
    }
};

class linked_list{
public:
    node *head, *prev;
    linked_list(){
        head = nullptr;
    }

    void append(signed coef, int x, int y, int z){
        node *n = new node(coef, x, y, z);
        if(!head){
            head = n;
            return;
        }
        node *temp = head;
        while(temp->link){
            temp = temp->link;
        }
        temp->link = n;
    }
    void delete_specified(int coef){
        node *curr = head, *previous;
        while(curr->coef != coef){
            previous = curr;
            curr = curr->link;
        }
        previous->link = curr->link;
    }
    void display(){
        node *temp = head;
        cout<< "List elements are: " << endl;
        while(temp){
            cout << temp->coef << "(x" << temp->x << "y"<<temp->y <<"z"<<temp->z<< "), ";
            temp = temp->link;
        }
        cout<<endl;
    }
    int length(){
        int count =0;
        node *temp = head;
        while(temp){
            count++;
            temp = temp->link;
        }
        return count;
    }
};

int ABC(node *p){
    return p->x + p->y + p->z;
}

node* add_poly(node *p, node *q){
    node *q1 = nullptr;

    if(ABC(p) < ABC(q)){[
        q1 = q;
        q = q->link;
    }
    else if(ABC(p) == ABC(q)){
        if(p->x == q->x && p->y == q->y && p->z == q->z){

        }
    }


}

int main()
{
    linked_list ll;

    ll.append(+1, 4, 0, 0);
    ll.append(+2, 3, 1, 0);
    ll.append(+3, 2, 2, 0);
    ll.append(+4, 1, 3, 0);
    ll.append(+5, 0, 4, 0);

    ll.display();


    return 0;
}
