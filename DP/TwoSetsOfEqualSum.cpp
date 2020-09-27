// Your task is to count the number of ways numbers 1,2,…,n can be divided into two sets of equal sum.


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


void solve()
{
    int n; 
    cin>>n;
    int target = n*(n+1)/2;
    if(target%2)
    {
        cout<<0<<"\n";
        return ;
    }
    target /= 2;

    vector<vector<int>> dp(n,vector<int>(target+1,0));
    dp[0][0] = 1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=target;j++)
        {
            dp[i][j] = dp[i-1][j];
            int left = j-i;
            if(left>=0)
            {
                dp[i][j] += dp[i-1][left];
                if(dp[i][j]>mod)
                    dp[i][j] -= mod;
            }
        }
    }
    cout<<dp[n-1][target]<<"\n";

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