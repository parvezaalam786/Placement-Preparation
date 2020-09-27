#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL);
#define input freopen("Test.txt","r",stdin)
#define output freopen("Output.txt","w",stdout);
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define F(i,a,b) for(int i = a; i <= b; i++)
#define pb push_back
#define eb emplace_back
#define inf 1000000000
const double pi = 3.141592653589793238460;
#define debug false
#define mod 1000000007

ll cell(ll int n,ll int x,ll int y,ll int z)
{
	ll int dp[n+1];
	// Bottom up dp
	dp[0] = 0;
	dp[1] = 0;
	F(i,2,n)
	{
		if(i%2==0)
		{
			dp[i] = min(dp[i/2]+x,dp[i-1]+y);
		}
		else
		{
			dp[i] = min(dp[i-1]+y,dp[(i+1)/2]+x+z);
		}		
	}
	return dp[n];
}



void solve()
{
	int n,x,y,z;
	cin>>n>>x>>y>>z;
	cout<<cell(n,x,y,z)<<"\n";

}

int main()
{
    // fast_io; // input; // output; // if(debug){watch_is();}
    solve();   
    return 0;
}