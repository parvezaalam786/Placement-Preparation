#include<bits/stdc++.h>
using namespace std;
class Graph
{
    map<int,list<int> > adjList;
public:
    Graph()
    {
    }
    void addEdge(int u,int v,bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void print()
    {
        for(auto i:adjList)
        {
            cout<<i.first<<"->";
            for(int j:i.second)
            {
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
    void dfsHelper(int node,map<int,bool> &visited)
    {
        //whenever comes to a node mark it visited
        visited[node] = true;
        cout<<node<<" ";

        //finding a current which is a neighbour of the current node and not yet visited
        for(int x:adjList[node])
        {
            if(!visited[x])
            {
                dfsHelper(x,visited);
            }
        }
    }
    void dfs(int src)
    {
        map<int,bool> visited;
        dfsHelper(src,visited);
        int component = 1;
        cout<<endl;
        for(auto i:adjList)
        {
            int x = i.first;
            if(!visited[x])
            {
                dfsHelper(x,visited);
                component++;
            }
        }
    cout<<"The given graph has "<<component<<" component\n";
    }
};
int main()
{
    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,4);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(6,7);
    g.addEdge(7,8);

    g.dfs(0);
    return 0;
}

