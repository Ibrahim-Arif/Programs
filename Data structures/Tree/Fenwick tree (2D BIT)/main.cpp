#include <iostream>
#include <vector>
#define s 4
using namespace std;

class BITree{
private:
    int **BIT;
    int size;

    int getSum(int index, int y){
        int sum = 0;
        index++;
        while(index > 0){
            sum += BIT[y][index];
            index = index - (index & (-index));
        }
        return sum;
    }
    int getSum(int from, int to, int y){
        return ( getSum(to, y) - getSum(from-1, y) );
    }

public:
    BITree(){
        size = s+1;
        BIT = new int*[size];

        for(int i=0; i<size; i++)
            BIT[i] = new int[size]{0};
    }

    void createBIT(int arr[][s]){
        for(int i=0; i<s; i++){
            for(int j=0; j<s; j++)
                add(i, j, arr[i][j] );
        }
    }

    void add(int x, int y, int value){
        y++;
        while(y <= size){
            BIT[x][y] += value;
            y = y + (y & (-y));
        }
    }

    int getSum(int x1, int x2, int y1, int y2){                     // return sum of x1 to x2 from y1 to y2
        int sum=0;
        for(int i=y1; i<=y2; i++)
            sum += getSum(x1, x2, i);
        return sum;
    }

    void display(){
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++)
                cout<<BIT[i][j]<<", ";
            cout<<endl;
        }
        cout<<endl;
    }
};

int main()
{
    BITree bit;

    int arr[s][s] ={ {1, 2, 3, 4},
                            {5, 3, 8, 1},
                            {4, 6, 7, 5},
                            {2, 4, 8, 9} };

    bit.createBIT(arr);
    bit.display();

    cout<<"ANS: "<<bit.getSum(2, 3, 2, 3)<<endl;

    cout<<"\nEnded"<<endl;
    return 0;
}

