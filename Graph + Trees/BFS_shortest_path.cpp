#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1100];
bool visited[1100];
int dist[1100];
void bfs(int src,int nodes)
{
    visited[src] = 1;
    dist[src] = 0;
    list<int> que;
    que.push_back(src);
    while(!que.empty())
    {
        int x = que.front();
        que.pop_front();
        for(auto i:adj[x])
        {
            if(visited[i]==false)
            {
                visited[i] = 1;
                dist[i] = dist[x]+1;
                que.push_back(i);
            }
        }
    }
    for(int i=1;i<=nodes;i++)
    {
        if(i==src)
            continue;
        if(dist[i]==-1)
            cout<<"-1 ";
        else cout<<dist[i]*6<<" ";
    }
    cout<<"\n";

}


int main()
{
    int T; cin>>T;
    while(T--)
    {
        memset(visited,false,sizeof(visited));
        memset(dist,-1,sizeof(dist));
        int n,m; cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int src; cin>>src;
        bfs(src,n);
        for(int i=0;i<1100;i++) 
            adj[i].clear();
    }
    return 0;
}