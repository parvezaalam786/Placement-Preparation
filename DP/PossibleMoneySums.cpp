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
    int n; cin>>n;
    int max_sum = n*1000;
    vector<int> x(n);
    F(i,0,n) cin>>x[i];

    vector<vector<bool>> dp(n+1,vector<bool>(max_sum+1,false));
    dp[0][0] = true;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=max_sum;j++)
        {
            dp[i][j] = dp[i-1][j];
            int left = j-x[i-1];
            if(left>=0 and dp[i-1][left])
            {
                dp[i][j] = true;
            }
        }
    }

    vector<int> changes;
    for(int j=1;j<=max_sum;j++)
    {
        if(dp[n][j])
        {
            changes.pb(j);
        }
    }
    cout<<changes.size()<<"\n";
    for(auto i:changes)
        cout<<i<<" ";
    cout<<"\n";
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