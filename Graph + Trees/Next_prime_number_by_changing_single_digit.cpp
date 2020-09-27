///https://www.spoj.com/problems/PPATH/
#include<bits/stdc++.h>
using namespace std;

map<int,list<int>> adjList;

void SieveOfEratosthenes(vector<int>& v)
{
	int n = 9999;
	bool prime[n+1];
	memset(prime,true,sizeof(prime));
	for(int p=2;p*p<=n;p++)
	{
		if(prime[p]==true)
		{
			for(int i=p*p;i<=n;i+=p)
			{
				prime[i] = false;
			}
		}
	}
	for(int i=1000;i<=n;i++)
		if(prime[i]){
			v.push_back(i);
		}			
}
int bfs(int num1,int num2,int nodes)
{
	int visited[nodes];
	memset(visited,0,sizeof(visited));
	queue<int> que;
	que.push(num1);
	visited[num1] = 1;
	while(!que.empty())
	{
		int p = que.front();
		que.pop();
		for(auto it1: adjList[p])
		{
			if(!visited[it1])
			{
				visited[it1] = visited[p]+1;
				que.push(it1);
			}
			if(it1==num2)
				return visited[it1]-1;
		}
	}
	//return 0;
}
bool compare(int n1,int n2)
{
	string s1 = to_string(n1); 
    string s2 = to_string(n2); 
    int c = 0; 
    if (s1[0] != s2[0]) 
        c++; 
    if (s1[1] != s2[1]) 
        c++; 
    if (s1[2] != s2[2]) 
        c++; 
    if (s1[3] != s2[3]) 
        c++;
	return (c==1); 	
}

void shortestPath(int num1,int num2)
{
	if(num1==num2)
		cout<<"0"<<endl;
	else
	{
		vector<int> v;
		SieveOfEratosthenes(v);
		for(int i=0;i<v.size();i++)
		{
			for(int j=i+1;j<v.size();j++)
			{
				if(compare(v[i],v[j]))
					adjList[i].push_back(j);
			}
		}
		int idx1,idx2;
		for(int i=0;i<v.size();i++)
		{
			if(v[i]==num1)
				idx1 = i;
		}
		for(int i=0;i<v.size();i++)
		{
			if(v[i]==num2)
				idx2 = i;
		}
		int ans = bfs(idx1,idx2,v.size());
		if(ans==0)
			cout<<"Impossible\n";
			else cout<<ans<<endl;
	}
	adjList.clear();
}

int main()
{
	int T; cin>>T;
	while(T--)
	{
		int a,b; cin>>a>>b;
		shortestPath(a,b);
	}
	return 0;
}