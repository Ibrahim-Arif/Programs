#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define max_n 20
using namespace std;

class graph{
private:
    int total_nodes=0, max_nodes = max_n;
    vector<pair<int, int>> edges;
    vector<int> adjacent_list[max_n];
    vector<int> weight[max_n];
    bool vertex_value[max_n] = {false};

    void printSolution(int dist[]) {
        printf("Vertex \t\t Distance from Source\n");
        for (int i = 0; i < max_nodes; i++) {
            if( !vertex_value[i] )
                continue;

            if(dist[i] != INT_MAX)
                printf("%d \t\t\t %d\n", i, dist[i]);
            else
                printf("%d \t\t\t Unreachable\n", i);
        }
    }

public:
    void addVertex(int key){
        vertex_value[key] = true;
        total_nodes++;
    }
    void addEdge(int vertex1, int vertex2, int weig){
        if(vertex_value[vertex1] && vertex_value[vertex2]){
            adjacent_list[vertex1].push_back(vertex2);
            weight[vertex1].push_back(weig);
            edges.push_back( make_pair(vertex1, vertex2) );
        }
    }
    void show_connections(){
        for(int i=0; i<max_nodes; i++){
            if(vertex_value[i]){
                cout<< i << "--> ";

                int j=0;
                for(auto it = adjacent_list[i].begin(); it != adjacent_list[i].end(); it++)
                    cout<< *it << "(" << weight[ i ][ j++ ] << "), ";

                cout<<endl;
            }
        }
    }
    void shortest_path(int key){            // using Bellman Ford algorithm
        int dist[max_nodes];
        int u, v, j, prev;

        for(int i=0; i<max_nodes; i++)
            dist[i] = INT_MAX;
        dist[key] = 0;

        for(int count=0; count<total_nodes; count++)
        {
            for(int i=0; i<edges.size(); i++){
                prev = u;
                u = edges[i].first;
                v = edges[i].second;
                if(u != prev)
                    j = 0;

                if(dist[u] + weight[u][j] < dist[v])
                    dist[v] = dist[u] + weight[u][j];
                j++;
            }
        }
        printSolution(dist);
    }

};

int main()
{
    graph g;

    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);
    g.addVertex(7);

    g.addEdge(1, 2, 6);
    g.addEdge(1, 3, 5);
    g.addEdge(1, 4, 5);

    g.addEdge(2, 5, -1);

    g.addEdge(3, 2, -2);
    g.addEdge(3, 5, 1);

    g.addEdge(4, 3, -2);
    g.addEdge(4, 6, -1);

    g.addEdge(5, 7, 3);

    g.addEdge(6, 7, 3);

    g.shortest_path( 1 );

/*
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);

    g.addEdge(1, 2, 4);
    g.addEdge(1, 4, 5);

    g.addEdge(3, 2, -10);

    g.addEdge(4, 3, 3);

    g.shortest_path(1);
*/

    return 0;
}
