#include <iostream>                 // https://www.hackerrank.com/challenges/maximum-cost-queries/problem
#include <vector>
using namespace std;

class edge{
public:
    int v1, v2, weight;
    edge(){
        v1 = v2 = weight = 0;
    }
    edge(int f, int s, int w){
        v1 = f;
        v2 = s;
        weight = w;
    }
};

class node{
public:
    int weight, parent;
    node(){
        weight = 0;
        parent = -1;
    }
    node(int w, int p){
        weight = w;
        parent = p;
    }
};

int totalPaths(vector<edge> edges, vector<node> parents, int l, int r){
    edge curr;
    int count = 0, next;
    for(unsigned int i=0; i<edges.size(); i++){
        curr = edges[i];
        if(parents[curr.v1].parent ==  curr.v2){
            if(parents[curr.v1].weight >=l && parents[curr.v1].weight <=r)
                count++;
            next = parents[curr.v1].parent;
        }
        else if(parents[curr.v2].parent == curr.v1){
            if(parents[curr.v2].weight >=l && parents[curr.v2].weight <=r)
                count++;
            next = parents[curr.v2].parent;
        }

        while(next > 0){
            if(parents[next].weight >=l && parents[next].weight <=r )
                count++;
            next = parents[next].parent;
        }
    }
    return count;
}

int main()              // this solution only works for given inputs on hacker rank.
{
    vector<edge> edges;
    int n, q, u, v, w, l, r, largest_vertex = 0;

    cin >> n;
    n--;
    cin >> q;

    while(n--){
        cin >> u;
        cin >> v;
        cin >> w;
        edges.push_back( edge(u, v, w) );

        if( u > largest_vertex )
            largest_vertex = u;
        if( v > largest_vertex )
            largest_vertex = v;
    }

    vector<node> parents(largest_vertex+1, node());
    edge curr;

    for(unsigned int i=0; i<edges.size(); i++){
        curr = edges[i];

        if( parents[curr.v1].parent == -1){
            parents[curr.v1].parent = curr.v2;
            parents[curr.v1].weight = curr.weight;
        }
        else{
            parents[curr.v2].parent = curr.v1;
            parents[curr.v2].weight = curr.weight;
        }
    }

    for(int i=0; i<parents.size(); i++)
        cout<<"("<<parents[i].parent<<", "<<parents[i].weight<<"), ";

    cout<<endl;

    while(q--){
        cin >> l;
        cin >> r;

        cout<<"--> "<<totalPaths(edges, parents, l, r)<<endl;
    }

    return 0;
}
