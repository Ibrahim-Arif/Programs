#include <iostream>                                 // https://www.hackerrank.com/challenges/components-in-graph/problem
#include <vector>
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
    for(unsigned int i=1; i<v.size(); i++)
        cout << v[i] << ", ";
    cout<<endl<<endl;
}
int Find(vector<int> &parents, int vertex){
    if(parents[vertex] < 0)
        return vertex;
    return Find(parents, parents[vertex]);
}
void Union(vector<int> &parents, int x, int y){
    if(parents[x] < parents[y]){
        parents[x] += parents[y];
        parents[y] = x;
    }else{
        parents[y] += parents[x];
        parents[x] = y;
    }
}

int main()
{
    int n, g, b, largest_vertex =0;
    vector<edge> edges;
    cin >> n;
    while(n--){
        cin >> g;
        cin >> b;
        edges.push_back( edge(g, b) );

        if(g > largest_vertex)
            largest_vertex = g;
        if(b > largest_vertex)
            largest_vertex = b;
    }

    int max=0, min;
    vector<int> parents(largest_vertex+1, -1);
    for(int i=0; i<edges.size(); i++){
        int p1 = Find(parents, edges[i].v1);
        int p2 = Find(parents, edges[i].v2);

        Union(parents, p1, p2);

        if(parents[p1] < max && parents[p1]<0)
            max = parents[p1];
        if(parents[p2] < max && parents[p2]<0)
            max = parents[p2];
    }

    print(parents);

    min = max;
    for(int i=0; i<parents.size(); i++){
        if(parents[i] > min && parents[i] < -1)
            min = parents[i];
    }

    cout<< (-1 * min)<<" "<<(-1 * max)<<endl;
    return 0;
}
