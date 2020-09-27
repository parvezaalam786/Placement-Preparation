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

const int maxn = 1000001;
vector<int> adjList[maxn];
bool visited[maxn];
int cc[maxn],curr_cc;

void dfs(int node)
{
    visited[node] = true;
    cc[node] = curr_cc;
    for(int child:adjList[node])
    {
        if(visited[child]==false)
        {
            dfs(child);
        }
    }

}

void solve()
{
    int T,n,k,a,b;
    string op1;
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        curr_cc = 0;
        vector<pair<int,int> > EdgeList;    
        F(i,1,n+1)
        {
            adjList[i].clear();
            visited[i] = 0;
        }
        F(i,1,k+1)
        {
            cin>>a>>op1>>b;
            if(op1 == "=")
            {
                adjList[a].pb(b);
                adjList[b].pb(a);
            }
            else
            {
                EdgeList.push_back({a,b});
            }   
        }

        F(i,1,n+1)
        {
            if(visited[i] == 0)
            {
                curr_cc++;
                dfs(i);
            }
        }

        bool flag = true;
        F(i,0,EdgeList.size())
        {
            a = EdgeList[i].first;
            b = EdgeList[i].second;
            if(cc[a] == cc[b])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cout<<"YES"<<'\n';
        }
        else
        {
            cout<<"NO"<<"\n";
        }
        
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