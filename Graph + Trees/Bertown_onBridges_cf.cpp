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

const int maxn = 100001;
vector<int> adj[maxn];
int in[maxn],low[maxn],visited[maxn],timer;
bool hasBridge;
vector<pair<int,int> > edgeList; 

void dfs(int node,int par)
{
	visited[node] = 1;
	in[node] = low[node] = timer++;

	for(int child:adj[node])
	{
		if(child==par) continue;

		if(visited[child])
		{
			low[node] = min(low[node],in[child]);
			if(in[node]>in[child]) //here the current node is descendent and child is ancestor
				edgeList.push_back({node,child});
		}
		else
		{
			dfs(child,node);
			//only forward edges can be brides
			if(low[child]>in[node])  //if it happens then it is brodge
			{
				hasBridge = true;
				return;
			}
			edgeList.push_back({node,child});
			low[node] = min(low[node],low[child]);
		}		
	}
}

void solve()
{
	int n,m,a,b;
	cin>>n>>m;
	while(m--)
	{
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,-1);

	if(hasBridge)
	{
		cout<<0<<"\n";
	}
	else
	{
		for(auto i:edgeList)
			cout<<i.first<<" "<<i.second<<"\n";
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
