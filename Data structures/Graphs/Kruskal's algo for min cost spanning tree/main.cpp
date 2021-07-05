#include <iostream>
#include <vector>
using namespace std;

class edge{
public:
    int src, desc, weight;
    edge(){
        weight=0;
    }
    edge(int s, int d, int w){
        src = s;
        desc = d;
        weight = w;
    }
};

template<class T>
class minHeap{
public:
    T *heapp, *root;
    int index, tail, size;

    minHeap(int cap){
        heapp = new T[cap]{edge()};
        size = cap;
        root = nullptr;
        index = 1;
        tail = cap-1;
    }

    void    insert(T ele){
        if( !heapp[1].weight ){
            heapp[index++] = ele;
            return;
        }
        int i = index, j;
        T temp;
        heapp[index] = ele;

        while(i != 1){
            j = i;                                  //previous index of last smallest swap
            i /= 2;                                // parent of i = i/2
            if(ele.weight < heapp[i].weight){              // '< ' for min heap
                temp = heapp[i];
                heapp[i] = ele;
                heapp[j] = temp;
            }
        }
        index++;
    }
    int       min(int a, int b){
        return (heapp[a].weight < heapp[b].weight) ? a : b;
    }
    int       leftChild(int i){
        return 2*i;
    }
    int       rightChild(int i){
        return (2*i)+1;
    }
    T    deleteTop(){
        if(index == 1){
            cout<< "Heap is empty!"<<endl;
            return edge();
        }
        T ele = heapp[1];                             // smallest element into last index, for sorting
        heapp[1] = heapp[--index];            // last element of heap to root (temporary)

        int i = 1, mini;
        T temp;
        while(i < index){
            if(leftChild(i)>index || rightChild(i)>index)               // if any index have no child then break
                break;

            mini = min( leftChild(i), rightChild(i) );
            if(heapp[mini].weight < heapp[i].weight){
                temp = heapp[i];
                heapp[i]= heapp[mini];
                heapp[mini] = temp;
            }
            i = mini;
        }
        //heapp[tail--] = ele;
        return ele;
    }
};

void print(vector<int> v){
    for(unsigned int i=0; i<v.size(); i++)
        cout<<i<<", \t";
    cout<<endl;

    for(unsigned int i=0; i<v.size(); i++){
        if(v[i] != -1)
            cout << v[i] << ", \t";
        else
            cout << ", \t";
    }
    cout<<endl<<endl;
}

int Find(vector<int> &parents, int vertex){
    if(parents[vertex] < 0)
        return vertex;
    return Find(parents, parents[vertex]);
}
void Union(vector<int> &parents, int x, int y){
    parents[x] = y;
}

bool kruskal(minHeap<edge> heap, int highest_vertex){
     vector<int> parents(highest_vertex+1, -1);
     int p1, p2, weight =0;
     bool isCycle = false;
     edge curr;

     for(int i=0; i<heap.size; i++){
        curr = heap.deleteTop();

        p1 = Find(parents, curr.src);
        p2 = Find(parents, curr.desc);

        if(p1 != p2){
            if(parents[p1] < parents[p2]){
                parents[p1] += parents[p2];
                Union(parents, p2, p1);
            }else{
                parents[p2] += parents[p1];
                Union(parents, p1, p2);
            }
            weight += curr.weight;
            cout<<curr.src<<" -- "<<curr.desc<<" = "<<curr.weight<<endl;
        }
        else
            isCycle = true;
    }
    cout<<"\nAfter removing cycle:" <<endl;
    print(parents);

    cout<<"weight: "<<weight<<endl;
    return isCycle;
}

int main()
{
    minHeap<edge> heap(10);             // size should be 1 greater than total edges.

    heap.insert(edge(1, 6, 10));
    heap.insert(edge(1, 2, 28));
    heap.insert(edge(6, 5, 25));
    heap.insert(edge(5, 7, 24));

    heap.insert(edge(2, 7, 14));
    heap.insert(edge(2, 3, 16));
    heap.insert(edge(5, 4, 22));
    heap.insert(edge(7, 4, 18));

    heap.insert(edge(3, 4, 12));

/*
    heap.insert(edge(5, 7, 1));
    heap.insert(edge(5, 6, 3));

    heap.insert(edge(6, 8, 2));
    heap.insert(edge(6, 9, 6));

    heap.insert(edge(7, 8, 7));
    heap.insert(edge(8, 9, 9));
*/
/*
    heap.insert(edge(0, 1, 10));
    heap.insert(edge(0, 2, 6));
    heap.insert(edge(0, 3, 5));
    heap.insert(edge(1, 3, 15));
    heap.insert(edge(2, 3, 4));
*/

    if(kruskal(heap, 7))                                            //second parameter is highest vertex.
        cout<<"Cycle detected"<<endl;
    else
        cout<<"No cycle detected" <<endl;

    return 0;
}
