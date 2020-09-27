// you are given an array of size n (consisting of 0 and 1 only) and k = a1a2 + a2a3 + a3a4 + … an-1an.
//  You have to find out how many combinations of these light bulbs of size n (on and off) will give the sum of products equal to given value k. 
// You have to calculate this value modulo 10^6+3.

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
#define debug false
ll mod = 1e6+3;

ll n,k;
ll dp[200][2][200];
ll fun(ll idx,ll prev,ll cnt)
{
    if(idx==n)
    {
        if(cnt==k)
            return 1;
        return 0;
    }
    if(dp[idx][prev][cnt]!=-1)
        return dp[idx][prev][cnt];
    
    ll res = 0;
    if(prev == 1)
        res = res+fun(idx+1,1,cnt+1);
    else 
        res = res+fun(idx+1,1,cnt);
    
    res %= mod;
    res  = res+fun(idx+1,0,cnt);
    res %= mod;

    return dp[idx][prev][cnt] = res;
}
void solve()
{
    ll T;
    cin>>T;
    while(T--)
    { 
        memset(dp,-1,sizeof(dp));
        cin>>n>>k;
        ll ans = (fun(1,0,0)+fun(1,1,0))%mod;
        cout<<ans<<"\n";
    }
}

int main()
{
    // fast_io;
    // input;
    // output;
    // if(debug)
    // {
    //     watch_is();
    // }
    
    solve();   
    return 0;
}