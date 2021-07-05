#include <iostream>                         // https://www.hackerrank.com/challenges/queries-with-fixed-length/problem
using namespace std;

class queue{
public:
    int top, cap;
    int *arr;

    queue(){}
    queue(int c){
        cap = c;
        top = -1;
        arr = new int[c];
    }
    void push(int ele){
        if(top == cap-1){
            cout << "Queue overloaded!" << endl;
            return;
        }
        arr[++top] = ele;
    }
    void push_all(int arr[], int n){
        for(int i=0; i<n; i++)
            push(arr[i]);
    }
    int pop(){
        int ele = arr[0];
        for(int i=0; i<top; i++)
            arr[i] = arr[i+1];
        top--;
        return ele;
    }
    void display(){
        for(int i=0; i<=top; i++)
            cout<<arr[i]<<", ";
        cout<<endl;
    }
    bool isEmpty(){
        return top == -1 ? true : false;
    }
    int length(){
        return top+1;
    }
};

int main()
{
    int n, q, max, min, qn, ele, q2_l;
    bool flag;
    cin >> n;
    cin >> q;
    queue q1(n), q2(n);
    int arr[n], queries[q];

    for(int i=0; i<n; i++)
        cin >> arr[i];
    for(int i=0; i<q; i++)
        cin >> queries[i];


    for(int i=0; i<q; i++){
        qn = queries[i];                            // number of integers to check for MAX each time.
        min = 999999;
        flag = false;                                   // in case if pushing on q2 after visiting q1
        q1.top = q2.top = -1;                   // emptying queues for next iterations.
        q1.push_all(arr, n);                     // pushing complete array on q1

        while( !q1.isEmpty() ){
            max = 0;

            q2_l = q2.length();
            if( !q2.isEmpty() ){                // if q2 is not empty then first then first pop all from q2 before q1
                flag = true;                        //  flag must be high so that if we push onto q2 later then every element must be pushed on q2 form q1 even first popped
                for(int k=0; k<q2_l; k++){
                    ele = q2.pop();
                    if(ele > max)
                        max = ele;
                    if(k)                               // don't save first popped from q2 because we are leaving one left element in every iteration form start.
                        q2.push(ele);
                }
            }
            for(int k=0; k<qn-q2_l; k++){
                ele = q1.pop();
                if(ele > max)
                    max = ele;
                if(k || flag)                          // here if we are here before above if then first pop should not be pushed onto q2
                    q2.push(ele);               //  but if above if is been visited then every popped is important and must be pushed onto q2
            }
            if(max < min)
                min = max;
        }
        cout<<min<<endl;
    }
    return 0;
}
