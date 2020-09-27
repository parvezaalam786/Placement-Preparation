#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL);
#define input freopen("Test.txt","r",stdin)
#define output freopen("Output.txt","w",stdout);
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define pb push_back
#define eb emplace_back
#define inf 1000000000
const double pi = 3.141592653589793238460;
#define debug false
#define mod 1000000007

// n = egges, k = floors
int eggDrop(int n,int k)
{
    int dp[n+1][k+1];
    int res;
    int i,j,x;

    // We need one trial for one floor and 0 trials for 0 floors 
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    // We always need j trials for one egg and j floors.
    for(int j=1;j<=k;j++) 
        dp[1][j] = j;
    
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=k;j++)
        {
            dp[i][j] = inf;
            for(int x = 1;x<=j;x++)
            {
                res = 1+max(dp[i-1][x-1],dp[i][j-x]);
                if(res<dp[i][j])
                    dp[i][j] = res;
            }
        }
    }
    return dp[n][k];
}

void solve()
{
    int n=2,k=36;
    cout<<"Minimum number of trials in worst case is "<<eggDrop(n,k)<<"\n";
}

int main()
{
    // fast_io; // input; // output; // if(debug){watch_is();}
    solve();   
    return 0;
}