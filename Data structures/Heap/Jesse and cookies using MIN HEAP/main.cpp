#include <iostream>                         // https://www.hackerrank.com/challenges/jesse-and-cookies/problem
using namespace std;

template<class T>
class heap{
public:
    T *heapp, *root;
    int index, tail, size;

    heap(int cap){
        heapp = new T[cap];
        size = cap;
        root = nullptr;
        index = 1;
        tail = cap-1;
    }

    void    insert(T ele){
        if( !heapp[1] ){
            heapp[index++] = ele;
            return;
        }
        int i = index, j, temp;
        heapp[index] = ele;

        while(i != 1){
            j = i;                                  //previous index of last greatest swap
            i /= 2;                                // parent of i = i/2
            if(ele < heapp[i]){              // '< ' for min heap
                temp = heapp[i];
                heapp[i]= ele;
                heapp[j] = temp;
            }
        }
        index++;
    }
    void    display(){
        if(index == 1){
            cout << "heap is empty!" << endl;
            return;
        }
        for(int i=1; i<index; i++)
            cout << heapp[i] << ", " ;
        cout << endl;
    }
    int       min(int a, int b){
        return (heapp[a] < heapp[b]) ? a : b;
    }
    int       leftChild(int i){
        return 2*i;
    }
    int       rightChild(int i){
        return (2*i)+1;
    }
    T    delete_top(){
        if(index == 1){
            return -1;
        }
        int ele = heapp[1];
        heapp[tail--] = ele;                 //largest element into last index, for sorting
        heapp[1] = heapp[--index];            //last element of heap to root (temporary)

        int i = 1, mini;
        T temp;
        while(i < index){
            if(leftChild(i)>index || rightChild(i)>index)       break;          // if any index have no child then break;

            mini = min( leftChild(i), rightChild(i) );
            if(heapp[mini] < heapp[i]){
                temp = heapp[i];
                heapp[i] = heapp[mini];
                heapp[mini] = temp;
            }
            i = mini;
        }
        return ele;
    }
    T         min_ele(){
        return heapp[1];
    }
};

int main()
{
    int n, k, ele, count=0, first, second;
    cin >> n;
    cin >> k;

    heap<int> h(n*10);

    for(int i=0; i<n; i++){
        cin >> ele;
        h.insert(ele);
    }

    while(h.min_ele() < k){
        count++;
        first = h.delete_top();
        second = h.delete_top();

        if(first == -1 || second == -1){
            count = -1;
            break;
        }

        ele = (1 * first) + (2 * second) ;
        h.insert(ele);
    }
    cout<<count<<endl;

    return 0;
}
