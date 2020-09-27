#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL);
#define input freopen("Test.txt","r",stdin)
#define output freopen("Output.txt","w",stdout);
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define F(i,a,b) for(int i = a; i < b; i++)
#define MAX(a,b,c) max(a,max(b,c))
#define MIN(a,b,c) min(a,min(b,c))
#define pb push_back
#define eb emplace_back
#define inf 1000000000
const double pi = 3.141592653589793238460;
#define debug false
#define MAXN 100010
#define mod 1000000007

int findMaxLen(char str[])
{
	int n = strlen(str);
	stack<int> stk;
	stk.push(-1);
	int result = 0;

	for(int i=0;i<n;i++)
	{
		if(str[i]=='(')
			stk.push(i);
		else
		{
			stk.pop();
			if(!stk.empty())
			{
				result = max(result,i-stk.top());
			}
			else
				stk.push(i);
		}
	}
	return result;
}

void solve()
{
	char s[100010];
	cin>>s;
	int ans = findMaxLen(s);
	cout<<ans<<"\n";    
}

int main()
{
     // input; // output; // if(debug){watch_is();}
    fast_io;
    solve();   
    return 0;
}