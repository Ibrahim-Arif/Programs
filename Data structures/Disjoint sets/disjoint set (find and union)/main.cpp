#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class edge{
public:
    int v1, v2;
    edge(){
        v1 = v2 = 0;
    }
    edge(int f, int s){
        v1 = f;
        v2 = s;
    }
};

void print(vector<int> v){
    for(unsigned int i=0; i<v.size(); i++)
        cout<<i<<", \t";
    cout<<endl;

    for(unsigned int i=0; i<v.size(); i++)
        cout << v[i] << ", \t";
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
bool isCycle(vector<edge> edges, int highest_vertex){
     vector<int> parents(highest_vertex+1, -1);
     int p1, p2;
     bool isCycle = false;
     edge curr;

    for(unsigned int i=0; i<edges.size(); i++){
        curr = edges[i];

        p1 = Find(parents, curr.v1);
        p2 = Find(parents, curr.v2);

        if(p1 != p2){
            if(parents[p1] < parents[p2]){
                parents[p1] += parents[p2];
                Union(parents, p2, p1);
            }else{
                parents[p2] += parents[p1];
                Union(parents, p1, p2);
            }
        }
        else
            isCycle = true;
        print(parents);
    }
    cout<<"After removing cycle:" <<endl;
    print(parents);

    return isCycle;
}

int main()
{
    vector<edge> edges;
/*
    edges.push_back( edge(1, 2) );
    edges.push_back( edge(3, 4) );
    edges.push_back( edge(5, 6) );
    edges.push_back( edge(7, 8) );

    edges.push_back( edge(2, 4) );
    edges.push_back( edge(2, 5) );
    edges.push_back( edge(1, 3) );
    edges.push_back( edge(6, 8) );

    edges.push_back( edge(5, 7) );
*/
/*   edges.push_back( edge(7, 6) );
    edges.push_back( edge(8, 2) );
    edges.push_back( edge(6, 5) );
    edges.push_back( edge(0, 1) );

    edges.push_back( edge(2, 5) );
    edges.push_back( edge(8, 6) );
    edges.push_back( edge(2, 3) );
    edges.push_back( edge(7, 8) );

    edges.push_back( edge(0, 7) );
    edges.push_back( edge(1, 2) );
    edges.push_back( edge(3, 4) );
    edges.push_back( edge(5, 4) );

    edges.push_back( edge(1, 7) );
    edges.push_back( edge(3, 5) );*/

    edges.push_back( edge(2, 3) );
    edges.push_back( edge(0, 3) );
    edges.push_back( edge(0, 2) );
    edges.push_back( edge(0, 1) );
    edges.push_back( edge(1, 3) );


    if(isCycle(edges, 3))
        cout<<"Alert! cycle detected. "<<endl;
    else
        cout<<"No, cycle detected. "<<endl;

    return 0;
}
