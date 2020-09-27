#include<bits/stdc++.h>
using namespace std;

///template<typename T>
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
    void bfs(int src)
    {
        queue<int> q;
        map<int,int> dist;
        map<int,int> parent;

        for(auto i:adjList){
            dist[i.first] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;
        parent[src] = src;

        while(!q.empty())
        {
            int node = q.front();
            cout<<node<<" ";
            q.pop();

            for(int x:adjList[node])
            {
                if(dist[x]==INT_MAX)
                {
                    q.push(x);
                    dist[x] = dist[node]+1;
                    parent[x] = node;
                }
            }
        }
        ///Print the distance to all the nodes
        for(auto i:adjList)
        {
            int node = i.first;
            cout<<"Dist of "<<node<<" from "<<src<<" is "<<dist[node]<<endl;
        }
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
    g.addEdge(3,5);
    g.addEdge(3,4);

    //g.print();
    g.bfs(0);


}
