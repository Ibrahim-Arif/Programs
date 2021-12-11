#include <iostream>
#include <vector>
using namespace std;

class BITree{
private:
    int *BIT;
    int size;

public:
    BITree(int s){
        size = ++s;
        BIT = new int[size]{0};
    }

    void createBIT(vector<int > arr){
        for(unsigned int i=0; i<arr.size(); i++)
            add(i, arr[i]);
    }

    void add(int index, int value){
        index++;
        while(index <= size){
            BIT[index] += value;
            index = index + (index & (-index));
        }
    }

    int getSum(int index){
        int sum = 0;
        index++;
        while(index > 0){
            sum += BIT[index];
            index = index - (index & (-index));
        }
        return sum;
    }

    int getSum(int from, int to){
        return ( getSum(to) - getSum(from-1) );
    }

    void display(){
        for(int i=0; i<size; i++)
            cout<<i<<", ";
        cout<<endl;

        for(int i=0; i<size; i++)
            cout<<BIT[i]<<", ";
        cout<<endl<<endl;
    }
};

int main()
{
    BITree bit(4);
    //vector<int> arr = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8 ,9};

    //vector<int> arr = {1, 2, 3, 4};
    //vector<int> arr = {5, 3, 8, 1};
    //vector<int> arr = {4, 6, 7, 5};
    vector<int> arr = {2, 4, 8, 9};

    bit.createBIT(arr);
    bit.display();

    /*cout<<"sum: "<<bit.getSum(10)<<endl;
    cout<<"sum: "<<bit.getSum(0, 11)<<endl;
    bit.add(6, 2);*/

    //bit.display();

    cout<<"\nEnded"<<endl;
    return 0;
}
