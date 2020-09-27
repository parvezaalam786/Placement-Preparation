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


void solve()
{
 	int w,h;
    cin>>w>>h;
    vector<vector<int>> dp(w+1,vector<int>(h+1));
    for(int i=0;i<=w;i++)
    {
        for(int j=0;j<=h;j++)
        {
            if(i==j)
                dp[i][j] = 0;
            else
            {   
                dp[i][j] = inf;
                for(int k=1;k<j;k++)
                {
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
                }
                for(int k=1;k<i;k++)
                {
                    dp[i][j] = min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
                }
            }
            
        }
    }
    cout<<dp[w][h]<<"\n";
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