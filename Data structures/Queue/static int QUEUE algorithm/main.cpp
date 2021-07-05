#include <iostream>
using namespace std;

class Student{
public:
    string name;
    int reg_no;
    Student(){
    }
    Student(string n, int reg){
        name = n;
        reg_no = reg;
    }
};

class queue{
private:
    int top, cap;
    Student *arr;

public:
    queue(){
    }
    queue(int c){
        cap = c;
        top = -1;
        arr = new Student[c];
    }
    void insert(Student stu){
        if(top == cap-1){
            cout << "Queue overloaded!" << endl;
            return;
        }
        arr[++top] = stu;
    }
    Student delete_std(){
        Student stu = arr[0];
        for(int i=0; i<top; i++)
            arr[i] = arr[i+1];
        top--;
        return stu;
    }
    void display(){                                     // not part of queue..
        for(int i=0; i<=top; i++){
            cout << "Name-reg: " << arr[i].name << "-" <<arr[i].reg_no << endl;
        }
    }
};

int main()
{
    int choice, size;
    Student stu;
    cout<< "Enter size: ";
    cin >> size;
    queue q(size);

    cout << "1: Insert \n2: Delete \n3: Display \n0: Exit" << endl;
     while(choice){
        cout<<"\nEnter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
                cout << "Enter name & reg no:  ";
                cin >> stu.name;
                cin >> stu.reg_no;
                q.insert(stu);
                break;
            } case 2:{
                stu = q.delete_std();
                cout << "Deleted student!" <<endl;
                cout << "Name-reg: " << stu.name << "-" <<stu.reg_no << endl;
                break;
            } case 3:{
                q.display();
                break;
            } case 0:{
                break;
            }
        }
     }
    return 0;
}
