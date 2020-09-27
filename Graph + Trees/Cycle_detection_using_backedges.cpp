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

template<typename T>
class Graph
{
	map<T,list<T> > adjList;
public:
	Graph()
	{

	}
	void addEdge(T u,T v,bool bidir=true)
	{
		adjList[u].push_back(v);
		if(bidir)
			adjList[v].push_back(u);
	}

	bool isCyclicHelper(T node,map<T,bool> &visited,map<T,bool> &inStack)
	{
		visited[node] = true;
		inStack[node] = true;

		for(auto i:adjList[node])
		{
			if((!visited[i]&&isCyclicHelper(i,visited,inStack))||inStack[i])
			{
				return true;
			}
		}
		inStack[node] = false;
		return false;
	}

	bool isCyclic()
	{
		map<T,bool> visited;
		map<T,bool> inStack;

		for(auto i:adjList)
		{
			T node = i.first;
			if(!visited[node])
			{
				bool cyclePresent = isCyclicHelper(node,visited,inStack);
			}
		}
	}
};

void solve()
{
 	Graph<int> g;
	g.addEdge(0,2,false);
	g.addEdge(0,1,false);
	g.addEdge(2,3,false);
	g.addEdge(2,4,false);
	g.addEdge(3,0,false);
	g.addEdge(4,5,false);
	g.addEdge(1,5,false);
	if(g.isCyclic())
	{
		cout<<"Cycle present"<<"\n";
	}
	else
	{
		cout<<"Cycle not present"<<"\n";
	}
}

int32_t main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        // freopen("Test.txt","r",stdin);
        // freopen("Output.txt","w",stdout);
    #endif
    
     // if(debug){watch_is();}
    solve();   
    return 0;
}