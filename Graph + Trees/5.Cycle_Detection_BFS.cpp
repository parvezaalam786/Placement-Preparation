#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{

    map<T,list<T> > adjList;

public:
    Graph(){

    }
    void addEdge(T u,T v,bool bidir=true){

        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }
    ///Checking for undirected graph
    bool isCycleBFS(T src){
        map<T,bool> visited;
        map<T,int> parent;
        queue<T> q;

        q.push(src);
        visited[src] = true;
        parent[src] = src;

        while(!q.empty()){
            T node = q.front();
            q.pop();

            for(T x:adjList[node]){
                if(visited[x]==true && parent[node]!=x){
                    return true;
                }
                else if(!visited[x]){
                    visited[x] = true;
                    parent[x] = node;
                    q.push(x);
                }
            }
        }
        return false;
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(4,3);
    g.addEdge(2,3);

    if(g.isCycleBFS(1)){
        cout<<"Cyclic graph\n";
    }
    else{
        cout<<"Not Cyclic Graph\n";
    }
return 0;
}
