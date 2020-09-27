#include<bits/stdc++.h>
using namespace std;
vector<int> adj[20];
int main()
{
    int x,y,nodes,edges;
    bool bidirectional = false;
    cout<<"Enter number of nodes:\n";
    cin>>nodes;
    cout<<"Enter number of edges:\n";
    cin>>edges;
    cout<<"Bidirectioanl? 0/1\n";
    cin>>bidirectional;
    for(int i=0;i<edges;i++)   // one edge contains two nodes
    {
        cin>>x>>y;
        adj[x].push_back(y);
        if(bidirectional)
        {
            adj[y].push_back(x);
        }
    }
    for(int i=1;i<=nodes;i++)
    {
        cout<<"Adjacency list of node "<<i<<": ";
        for(int j=0;j<adj[i].size();j++)
        {
            if(j==adj[i].size()-1)
                cout<<adj[i][j]<<endl;
            else
                cout<<adj[i][j]<<" --> ";     
        }
    }
    return 0;
}