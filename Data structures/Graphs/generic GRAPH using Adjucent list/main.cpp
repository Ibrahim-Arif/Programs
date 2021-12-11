#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define max_n 20
using namespace std;

template<class T,class AL>
class graph{                                                    // undirected graph (2 way)
private:
    int total_nodes, max_nodes=max_n;
    vector<AL> adjacent_list[max_n];
    T *vertex_value = new T[max_n];

    int indexof(T ele){
        int i=0;
        while(vertex_value[i] != ele)
            i++;
        return i;
    }

public:
    graph(){
        total_nodes = 0;
    }

    void addVertex(int key, T v_v){
        vertex_value[key] = v_v;
        total_nodes++;
    }
    void addEdge(T node1, T node2){
        adjacent_list[ indexof(node1) ].push_back(indexof(node2));
        adjacent_list[ indexof(node2) ].push_back(indexof(node1));               // remove this to make it directed graph (one way)
    }
    void show_connections(){
        for(int i=0; i<max_nodes; i++){
            if(vertex_value[i] != ""){
                cout<< vertex_value[i] << " --> ";

                for(auto it = adjacent_list[i].begin(); it != adjacent_list[i].end(); it++)
                    cout<< vertex_value[*it] <<", ";

                cout<<endl;
            }
        }
        cout<<endl;
    }
    void BFS(T ele) {
        int curr_index, weig =0;
        bool flag;
        T curr_node;
        queue<T> q;
        bool *visited = new bool[total_nodes]{false};

        q.push(ele);
        visited[indexof(ele)] = true;
        cout<<ele << ": "<<weig <<", ";

        while( !q.empty() ){
            curr_node = q.front();
            q.pop();
            curr_index = indexof(curr_node);
            flag = true;

            for(auto it = adjacent_list[curr_index].begin(); it != adjacent_list[curr_index].end(); it++){
                if(!visited[ *it ] ){
                    if(flag){
                        weig++;                                     // only in first iteration weight will increment
                        flag = false;
                    }
                    q.push(vertex_value[*it]);
                    visited[ *it ] = true;
                    cout<<vertex_value[*it] << ": "<<weig <<", ";
                }
            }
        }
        cout<<endl;
    }
    void DFSutil(T ele, bool visited[] ){
        int curr_index = indexof(ele);
        visited[ curr_index ] = true;
        cout<< ele <<", ";

        for(auto it = adjacent_list[curr_index].begin(); it != adjacent_list[curr_index].end(); it++){
            if( !visited[ *it ] )
                DFSutil(vertex_value[*it], visited);
        }
    }
    void DFS(T ele){
        bool *visited = new bool[total_nodes]{false};

        DFSutil(ele, visited);
    }
    void isPathUtil(T source, T end, bool visited[]){
        int curr_index = indexof(source);
        visited[ curr_index ] = true;

        if(source == end){
            cout<< "Path exist towards: "<<end <<endl;
            return;
        }

        for(auto it = adjacent_list[curr_index].begin(); it != adjacent_list[curr_index].end(); it++){
            if( !visited[ *it ] )
                isPathUtil(vertex_value[*it], end, visited);
        }
    }
    void isPath(T source, T end){
        bool *visited = new bool[total_nodes]{false};

        isPathUtil(source, end, visited);
    }
};

int main()
{
    graph<string, int> g;

    g.addVertex(0, "ibrahim");
    g.addVertex(1, "burhan");
    g.addVertex(2, "arif");
    g.addVertex(3, "bilal");

    g.addVertex(4, "faizan");
    g.addVertex(5, "saad");
    g.addVertex(6, "nabeel");
    g.addVertex(7, "kashif");

    g.addVertex(8, "mushtak");
    g.addVertex(9, "zaleel");
    g.addVertex(10, "saud");
    g.addVertex(11, "zain");
    g.addVertex(12, "messi");

    g.addEdge("saad", "nabeel");
    g.addEdge("saad", "faizan");

    g.addEdge("ibrahim", "arif");
    g.addEdge("ibrahim", "bilal");
    g.addEdge("ibrahim", "nabeel");
    g.addEdge("ibrahim", "saad");
    g.addEdge("ibrahim", "messi");
    g.addEdge("ibrahim", "mushtak");
    g.addEdge("ibrahim", "zain");
    g.addEdge("ibrahim", "zaleel");

    g.addEdge("bilal", "faizan");
    g.addEdge("bilal", "saad");
    g.addEdge("bilal", "messi");
    g.addEdge("bilal", "zain");
    g.addEdge("bilal", "zaleel");

    g.addEdge("saud", "ibrahim");
    g.addEdge("saud", "burhan");
    g.addEdge("saud", "bilal");
    g.addEdge("saud", "saad");


    //g.isPath("ibrahim", "faizan");
    //g.BFS("ibrahim");
    g.DFS("saud");
    //g.show_connections();

    cout<<endl;
    return 0;
}
