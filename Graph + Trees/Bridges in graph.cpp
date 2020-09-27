#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define int long long
#define endl "\n"
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define F(i,a,b) for(int i = a; i < b; i++)
#define MAX(a,b,c) max(a,max(b,c))
#define MIN(a,b,c) min(a,min(b,c))
#define pb push_back
#define eb emplace_back
#define inf 1e9
const double pi = 3.141592653589793238460;
#define debug false
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define mod 1000000007
int min(int x,int y){ if(x<y) return x; return y; }
int max(int x,int y){ if(x<y) return y; return x; }

vector<int> adjList[100];
int in[101],low[101],vis[101];
int timer = 0;

void dfs(int node,int par)
{
    vis[node] = 1;
    in[node] = low[node] = timer++;
    for(auto child: adjList[node])
    {
        if(child == par) continue;
        if(vis[child]==1)
        {
            // edge node - child is a back edge
            // so minimize the low time of the current node
            low[node] = min(low[node],in[child]);
        }
        else
        {
            // edge node - child is a forward edge
            //only forward edges can be bridges
            dfs(child,node);
            if(low[child]>in[node])
                cout<<node<<" - > "<<child<<" is a bridge\n";
        
            low[node] = min(low[node],low[child]);        
        }       

    }
}


void solve()
{
	int n,m,x,y;
    cin>>n>>m;
    while(m--)
    {
        cin>>x>>y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    dfs(1,-1);

}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif

	// if(debug){watch_is();}
	solve();
	return 0;
}

/*
4 4
1 2
2 3
2 4
3 4

4 3
1 2
1 3
1 4

*/