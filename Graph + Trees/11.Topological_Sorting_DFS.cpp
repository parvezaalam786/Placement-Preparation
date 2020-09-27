
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{

    map<T,list<T> > adjList;
public:
    Graph(){

    }
    void addEdge(T u,T v,bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }
    void print()
    {
        for(auto i:adjList)
        {
            cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
    void dfsHelper(T node,map<T,bool> &visited,list<T> &ordering){

         visited[node] = true;
         ///will call dfs on the unvisited neighbours of the current node
         for(T x:adjList[node]){
            if(!visited[x]){
                dfsHelper(x,visited,ordering);
            }
         }
         ///this line for topological sorting
         ///At this point all the children of the current node have been visited
         ordering.push_front(node);
    }
    void dfsTopologicalSort(){
        map<T,bool> visited;
        list<T> ordering;
        for(auto i:adjList)
        {
            //i is a pair(node,list of nodes)
            T node = i.first;
            if(!visited[node]){
                dfsHelper(node,visited,ordering);
            }
        }
        ///Printing elements in the ordering
        for(T element:ordering){
            cout<<element<<"-->";
        }
    }
};

int main(){
    Graph<string> g;
    g.addEdge("English","Programming Logic",false);
    g.addEdge("Maths","Programming Logic",false);
    g.addEdge("Programming Logic","HTML",false);
    g.addEdge("Programming Logic","Python",false);
    g.addEdge("Programming Logic","Java",false);
    g.addEdge("Programming Logic","JS",false);
    g.addEdge("Python","Web Dev",false);
    g.addEdge("HTML","CSS",false);
    g.addEdge("CSS","JS",false);
    g.addEdge("JS","Web Dev",false);
    g.addEdge("Java","Web Dev",false);
    g.addEdge("Python","Web Dev",false);
    g.dfsTopologicalSort();
}
