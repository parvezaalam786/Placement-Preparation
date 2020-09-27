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
#define inf 1e18
const double pi = 3.141592653589793238460;
#define debug false
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define mod 1000000007

const int maxn = 100010;
bool visited[maxn];
int subtreeSize[maxn];
vector<int> adjList[maxn];

int dfs(int src)
{
    visited[src] = true;
    int curr_size = 1;
    for(auto x:adjList[src])
    {
        if(!visited[x])
        {
            curr_size += dfs(x);
        }
    }
    subtreeSize[src] = curr_size;
    return curr_size;
}

void solve()
{
    int nodes;
    cin>>nodes;
    F(i,0,maxn)
    {
        visited[i] = false;
        subtreeSize[i] = 0;
    }
    F(i,0,nodes-1)
    {
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int root;
    cin>>root;
    dfs(root);
    F(i,1,nodes+1)
        cout<<subtreeSize[i]<<" ";
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
input:
7
1 2
2 3
3 7
2 4
4 5
4 6
1
output:
7 6 2 3 1 1 1
*/