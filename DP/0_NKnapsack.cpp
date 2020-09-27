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

int knapsack(int W,int wt[],int val[],int n)
{
    int dp[W+1];
    memset(dp,0,sizeof(dp));
    int ans = 0;

    for(int i=0;i<=W;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(wt[j]<=i)
            {
                dp[i] = max(dp[i],dp[i-wt[j]]+val[j]);
            }
        }
    }
    return dp[W];
}

void solve()
{
    int n,W;
    cin>>n>>W;
    int wt[n],val[n];
    for(int i=0;i<n;i++)
        cin>>wt[i];
    for(int i=0;i<n;i++)
        cin>>val[i];
    int ans = knapsack(W,wt,val,n);
    cout<<ans<<"\n";    
}

int main()
{
     // input; // output; // if(debug){watch_is();}
    fast_io;
    solve();   
    return 0;
}