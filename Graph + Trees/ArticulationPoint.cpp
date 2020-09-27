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
int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}

vector<int> adj[10001];
int visited[10001],in[10001],low[10001];
set<int> AP;
int timer;

void dfs(int node,int par)
{
	visited[node] = 1;
	in[node] = low[node] = timer++;
	int child_cnt = 0;

	for(int child:adj[node])
	{
		if(child==par)
			continue;
		if(visited[child]==1)
		{
			low[node] = min(low[node],in[child]);
		}
		else
		{
			dfs(child,node);
			child_cnt++;
			low[node] = min(low[node],low[child]);
			if(in[node]<=low[child] and par!=-1)
			{
				AP.insert(node);
			}
		}
		if(par==-1 and child_cnt>1)
			AP.insert(node);
	}
}


void solve()
{
	int n,m,a,b;
	while(1)
	{
		cin>>n>>m;
		if(n==0 and m==0)
			break;
		for(int i=1;i<=n;i++)
			adj[i].clear(),visited[i] = 0;
		AP.clear();
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}	
		for(int i=0;i<n;i++)
		{
			if(visited[i]==0)
				dfs(i,-1);
		}
		cout<<AP.size()<<"\n";

	}
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
