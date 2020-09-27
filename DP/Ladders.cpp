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

int ladders_topdown(int n,int k,int dp[])
{
    if(n==0)
        return 1;
    if(dp[n]!=0)
        return dp[n];
    int ways = 0;
    for(int i=1;i<=k;i++)
    {
        if(n-i>=0)
            ways += ladders_topdown(n-i,k,dp);
    }
    return dp[n] = ways;
}

int ladders_bottomup(int n,int k)
{
    int dp[100] = {0};
    dp[0] = 1;
    for(int i=1;i<=n;i++)
    {
        dp[i] = 0;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
                dp[i] += dp[i-j];
        }
    }
    return dp[n];
}

// Another Optimised Implementation
int ladders_optimised(int n,int k)
{
    int dp[100] = {0};
    dp[0] = dp[1] = 1;
    for(int i=2;i<=k;i++)
    {
        dp[i] = 2*dp[i-1];
    }
    for(int i=k+1;i<=n;i++)
    {
        dp[i] = 2*dp[i-1]-dp[i-k-1];
    }
    for(int i=0;i<=n;i++)
        cout<<dp[i]<<" ";
    return dp[n];
}

void solve()
{
    int n,k;
    int dp[100] = {0};
    cin>>n>>k;
    cout<<ladders_topdown(n,k,dp)<<"\n";
    cout<<ladders_bottomup(n,k)<<"\n";
    cout<<ladders_optimised(n,k)<<"\n";
}

int main()
{
     // input; // output; // if(debug){watch_is();}
    fast_io;
    solve();   
    return 0;
} 