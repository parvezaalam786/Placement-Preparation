#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long int
const int sizes = 1e5+5;
vector<int> adj[sizes];
bool visited[sizes];

void dfs(int v){
    visited[v] = true;
    for(int a:adj[v]){
        if(!visited[a])
            dfs(a);
    }
}
int main()
{
    
    fast_io;
    //freopen("Test.txt","r",stdin);
    int n,m,k,u,v,count=0;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i);
            count++;
        }
    }
    if(count>k){
        cout<<"-1"<<endl;
    }
    else{
        cout<<m-n+k<<endl;
    }
    return 0;
}

