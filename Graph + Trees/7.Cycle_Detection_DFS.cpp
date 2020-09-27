#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{

    int V;
    map<T,list<T> > adjList;

public:
    Graph(int v){
        V = v;
    }
    void addEdge(T u,T v, bool bidir=true){

        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }
    bool isCyclicHelper(T node,map<T,bool> &visited,T parent){

        visited[node] = true;

        for(T x:adjList[node]){
            if(!visited[x]){
                bool cycleDetected = isCyclicHelper(x,visited,node);
                if(cycleDetected){
                    return true;
                }
            }
            ///in this neighbour is already visited
            else if(x!=parent){
                return true;
            }
        }
        return false;
    }

    ///Check for undirected graph
    bool isCycleDFS(){
            map<T,bool> visited;

        ///for finding cycle in every dfs tree
        for(auto i:adjList){
            T node = i.first;
            if(!visited[node]){
                bool ans = isCyclicHelper(node,visited,node);
                if(ans==true){
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    Graph<int> g(4);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(3,4);

    if(g.isCycleDFS()){
        cout<<"Cyclic Graph\n";
    }
    else{
        cout<<"Non cyclic graph\n";
    }
    return 0;
}
