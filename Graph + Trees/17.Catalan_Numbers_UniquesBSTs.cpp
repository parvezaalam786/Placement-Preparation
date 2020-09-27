#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll catalan(ll n){
    ll dp[n+1] = {0};
    dp[0] = 1;
    dp[1] = 1;
    ll ans = 0;
    for(ll i=2;i<=n;i++){
        for(ll j=0;j<i;j++){
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }
    return dp[n];
}

int main()
{
    ll ans = catalan(3);
    cout<<ans<<endl;
    return 0;
}