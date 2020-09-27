#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ll long long int

class Graph{
    map<int,list<int> > adjList;
public:
    Graph(){ }
    void addEdge(int u,int v,bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }
    void topologicalSort(){
        queue<int> q;
        map<int,bool> visited;
        map<int,int> indegree;

        for(auto i:adjList){
            int node = i.first;
            visited[node] = false;
            indegree[node] = 0;
        }

        //Initializing the indegree of all nodes
        for(auto i:adjList){
            int u = i.first;
            for(int v:adjList[u]){
                indegree[v]++;
            }
        }

        //Finding nodes with indegree zero
        for(auto i:adjList){
            int node = i.first;
            if(indegree[node]==0){
                q.push(node);
            }
        }

        //Starting with the algorithm
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cout<<node<<"-->";

            for(int x :adjList[node]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }
    }
};


int main()
{
    //fast_io;
    //freopen("Test.txt","r",stdin);
    Graph g;
    g.addEdge(1,2,false);
    g.addEdge(1,3,false);
    g.addEdge(2,3,false);
    g.addEdge(2,4,false);
    g.addEdge(3,4,false);
    g.addEdge(3,5,false);

    g.topologicalSort();

    
}