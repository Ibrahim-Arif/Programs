#include <iostream>
using namespace std;

template<class T>
class Stack{
public:
    T *arr;
    int capacity, start_i, end_i, stack_index, top;

    Stack(){}
    Stack(T *a, int c, int s, int i){
        arr = a;
        capacity = c;
        top = s-1;
        start_i = s;
        end_i = s +(c-1);
        stack_index = i;
    }

    void push(T ele){
        if(isFull()){
            cout << "Stack["<< stack_index<<"] is overflow!" << endl;
            return;
        }
        arr[++top] = ele;
    }
    T pop(){
        if(isEmpty()){
            cout << "Stack["<< stack_index<<"] is underflow!" << endl;
            //return -1;
        }
        return arr[top--];
    }
    void traverse(){
        if(isEmpty()){
            cout << "Stack["<< stack_index<<"] is underflow!"<<endl;
            return;
        }
        cout << "\nStack["<< stack_index<<"] elements: \n" << endl;
        for(int i=top; i>=start_i; i--)
            if(i==top)  cout << "\t |  " << arr[i] << "  |  "<< i << " <- top"<<endl;
            else          cout << "\t |  " << arr[i] << "  |  "<< i <<endl;
        cout <<"\t -----------" <<endl;
    }
    bool isEmpty(){
        if(top == start_i-1)   return true;
        return false;
    }
    bool isFull(){
        if(top == end_i)   return true;
        return false;
    }
    int length(){
        return (top+1)-start_i;
    }
};

int main()
{
    int choice, len_a, total_s, each_cap, starting_index=0;          //change line 60, 64, 69, 71 data types to change stack data type..
    string ele;

    cout<<"Enter length of array: ";
    cin >> len_a;
    string *arr = new string[len_a];
    cout<<"Enter number of total stacks: ";
    cin >> total_s;
    each_cap = len_a/total_s;

    Stack<string> *stac = new Stack<string>[total_s];
    for(int i=0; i<total_s; i++){
        stac[i] = *new Stack<string>(arr, each_cap, starting_index, i);        // Stack(array, capacity, starting index, stack index)
        starting_index += each_cap;
    }

    cout << "\n1: Push \n2: Pop \n3: Traverse \n4: Length \n0: EXIT" << endl;
    while(choice){
        cout<<"\nEnter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
                cout<<"Enter stack index & element: ";
                cin>>starting_index;
                cin>>ele;
                stac[starting_index].push(ele);
                break;
            }
            case 2:{
                cout<<"Enter stack index: ";
                cin>>starting_index;
                ele = stac[starting_index].pop();
                /*if(ele != -1)   */cout<<"Pop from stack["<<starting_index<<"]: " << ele <<endl;
                break;
            }
            case 3:{
                cout<<"Enter stack index: ";
                cin>>starting_index;
                stac[starting_index].traverse();
                break;
            }
            case 4:{
                cout<<"Enter stack index: ";
                cin>>starting_index;
                cout<<"Stack[" <<starting_index<< "] length: " <<stac[starting_index].length()<<endl;
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
