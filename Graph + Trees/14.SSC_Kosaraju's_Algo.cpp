#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void fillOrder(int v,bool visited[],stack<int> &Stack);
    void DFSUtil(int v,bool visited[]);
public:
    Graph(int V);
    void addEdge(int u,int v);
    void printSSCs();
    Graph getTranspose();
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::DFSUtil(int v,bool visited[])
{
    visited[v] = true;
    cout<<v<<" ";
    for(auto i = adj[v].begin();i!=adj[v].end();i++)
    {
        if(!visited[*i]){
            DFSUtil(*i,visited);
        }
    }
}
Graph Graph::getTranspose()
{
    Graph g(V);
    for(int v=0;v<V;v++)
    {
        for(auto i = adj[v].begin();i!=adj[v].end();i++)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}
void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
}
void Graph::fillOrder(int v,bool visited[],stack<int> &Stack)
{
    visited[v] = true;
    for(auto i = adj[v].begin();i!=adj[v].end();i++)
    {
        if(!visited[*i]){
            fillOrder(*i,visited,Stack);
        }
    }
    Stack.push(v);
}
void Graph::printSSCs()
{
    stack<int> Stack;
    bool *visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
    }
    //Fill vertices in the stack according to their finishing time
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            fillOrder(i,visited,Stack);
        }
    }
    Graph gr = getTranspose();

    //Marking all the vertices not visited
    for(int i=0;i<V;i++){
        visited[i] = false;
    }
    while(Stack.empty()==false)
    {
        int v = Stack.top();
        Stack.pop();
        if(visited[v]==false)
        {
            gr.DFSUtil(v,visited);
            cout<<endl;
        }
    }
}
int main()
{
    Graph g(5);
    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(0,3);
    g.addEdge(3,4);
    cout<<"Strongly Connected Components are\n";
    g.printSSCs();
    return 0;
}

