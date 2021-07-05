#include <iostream>
using namespace std;

template<class T>
class queue{
public:
    int top, cap;
    T *arr;

    queue(){}
    queue(int c){
        cap = c;
        top = -1;
        arr = new T[c];
    }

    void push(T ele){
        if(top == cap-1){
            cout << "Queue overloaded!" << endl;
            return;
        }
        arr[++top] = ele;
    }
    T pop(){
        if(top < 0)
            cout<<"stack is empty."<<endl;
        else{
            T ele = arr[0];
            for(int i=0; i<top; i++)
                arr[i] = arr[i+1];
            top--;
            return ele;
        }
    }
    void display(){
        for(int i=top; i>=0; i--)
            cout << arr[i] << ", " ;
        cout<<endl;
    }
    int length(){
        return top+1;
    }
};

int main()
{
    int choice, size;
    string ele;                                        //  change 48, 52 data type to convert stack data type

    cout<<"Enter size: ";
    cin>>size;
    queue<string> q(size);

    cout << "1: Push \n2: Pop \n3: Display \n0: Exit" << endl;
     while(choice){
        cout<<"\nEnter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
                cout << "Enter element:  ";
                cin >> ele;
                q.push(ele);
                break;
            }
            case 2:{
                for(int i=1; i<q.length(); i++)
                    q.push(q.pop());
                cout<<"Popped element: " << q.pop() << endl;
                break;
            }
            case 3:{
                q.display();
                break;
            }
            case 0:{
                break;
            }
        }
     }
    return 0;
}
