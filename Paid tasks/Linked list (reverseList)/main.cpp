#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

struct Node *head = NULL,
            *tail = NULL;

struct Node {
    Node(int data = 0, Node *next = NULL) : data(data), next(next){}
    int data;
    Node *next;
};

// function to append data at the end of linked list
void append(int data){
    struct Node *n = (struct Node*) malloc(sizeof(struct Node));
    n->next = NULL;
    n->data = data;

    if(!head){
        head = n;
        tail = n;
        return;
    }
    tail->next = n;
    tail = n;
}

// helper function to display all elements of list.
void display(){
    struct Node *temp = head;
    while(temp){
        cout << temp->data << ", ";
        temp = temp->next;
    }
    cout << endl << endl;
}

// recursive function to reverse the linked list
// with return type of 'void'
void reverseList(struct Node **p){
    struct Node *curr = *p,
                *temp = curr->next;

    if (!temp || !*p) return;

    reverseList(&temp);
    curr->next->next = curr;
    curr->next = NULL;
    *p = temp;
}

void writeList(string filename){
	ofstream file(filename.c_str());
	struct Node *temp = head;
	
    while(temp){
        file << temp->data << ", ";
        temp = temp->next;
    }
    file << endl;
	file.close();
}

int main()
{
    append(1);
    append(2);
    append(3);
    append(4);
    append(5);

    cout << "Before reverse list: " << endl;
    display();

    reverseList(&head);
    writeList("reverseList1.txt");
    cout << "Reversed list is write in 'reverseList1.txt'" << endl;

    cout << "\n------------- Another example -------------" << endl << endl;
    head = tail = NULL;

    append(22);
    append(5);
    append(11);
    append(74);
    append(132);
    append(98);
    append(7);
    append(33);
    append(154);
    append(777);

    cout << "Before reverse list: " << endl;
    display();

    reverseList(&head);
    writeList("reverseList2.txt");
    cout << "Reversed list is write in 'reverseList2.txt'" << endl;

    return 0;
}
