#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL);
#define input freopen("Test.txt","r",stdin)
#define output freopen("Output.txt","w",stdout);
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define pb push_back
#define eb emplace_back
#define inf 1000000000
const double pi = 3.141592653589793238460;
#define mod 1000000007
ll dp[1000];
ll countWays(int n)
{
  if(dp[n]!=-1)
    return dp[n];
  if(n>2)
    return countWays(n-1)+(n-1)*countWays(n-2);
  else
      return dp[n] = n;
}

int main()
{
    fast_io;
    ///input;
    ///output;
    memset(dp,-1,sizeof(dp));
    int T; cin>>T;
    int n;
    while(T--)
    {
      cin>>n;
      cout<<countWays(n)<<endl;
    }
    return 0;
}