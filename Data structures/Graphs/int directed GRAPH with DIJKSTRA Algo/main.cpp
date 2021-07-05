#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#define max_n 20
using namespace std;

class graph{
private:
    int total_nodes=0, max_nodes = max_n;
    vector<int> adjacent_list[max_n];
    vector<int> weight[max_n];
    bool vertex_value[max_n] = {false};

    int shortest_index(int dist[], bool visited[]){
        int min = INT_MAX, min_index;

        for(int i=0; i<total_nodes; i++){
            if( !visited[i] && dist[i] <= min)
                min = dist[i], min_index = i;
        }
        return min_index;
    }
    void printSolution(int dist[]) {
        printf("Vertex \t\t Distance from Source\n");
        for (int i = 0; i < max_nodes; i++) {
            if( !vertex_value[i] )
                continue;

            if(dist[i] != INT_MAX)
                printf("%d \t\t %d\n", i, dist[i]);
            else
                printf("%d \t\t Unreachable\n", i);
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

    void shortest_path(int key){            // using dijkstra algo
        bool visited[max_nodes];
        int dist[max_nodes];
        int curr_node = key;

        for(int i=0; i<max_nodes; i++)
            dist[i] = INT_MAX, visited[i] = false;
        dist[key] = 0;

        for(int count=0; count<total_nodes; count++){
            curr_node = shortest_index(dist, visited);
            visited[curr_node] = true;

            for(int i=0; i< weight[curr_node].size(); i++){
                if( !visited[ adjacent_list[curr_node][i] ] &&                                                                         // vertex is not been visited
                    dist[curr_node] + weight[curr_node][i] < dist[ adjacent_list[curr_node][i] ] )            // new distance < original distance
                {
                        dist[ adjacent_list[curr_node][i] ] = dist[curr_node] + weight[curr_node][i];
                }
            }
        }
        printSolution(dist);
    }

};

int main()
{
    graph g;

    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);
    g.addVertex(7);
    g.addVertex(8);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);

    g.addEdge(1, 0, 4);
    g.addEdge(1, 7, 11);
    g.addEdge(1, 2, 8);

    g.addEdge(2, 1, 8);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(2, 3, 7);

    g.addEdge(3, 2, 7);
    g.addEdge(3, 5, 14);
    g.addEdge(3, 4, 9);

    g.addEdge(4, 3, 9);
    g.addEdge(4, 5, 10);

    g.addEdge(5, 4, 10);
    g.addEdge(5, 3, 14);
    g.addEdge(5, 2, 4);
    g.addEdge(5, 6, 2);

    g.addEdge(6, 5, 2);
    g.addEdge(6, 8, 6);
    g.addEdge(6, 7, 1);

    g.addEdge(7, 6, 1);
    g.addEdge(7, 8, 7);
    g.addEdge(7, 1, 11);
    g.addEdge(7, 0, 8);

    g.addEdge(8, 2, 2);
    g.addEdge(8, 6, 6);
    g.addEdge(8, 7, 7);


    //g.shortest_path(0);
    g.show_connections();


    return 0;
}
