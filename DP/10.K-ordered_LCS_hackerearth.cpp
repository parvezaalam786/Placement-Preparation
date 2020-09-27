// https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/

#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

#define ll long long int
#define mod 1000000007
#define INF 1000000009
#define F(i,a,b) for(ll i=a;i<=b;i++)

ll n,m,a[2005],b[2005];
ll dp[2005][2005][8];
ll max(ll a,ll b){
    if(a>b)
        return a;
    return b;    
}

ll f(ll i,ll j,ll k)
{
    if(i>=n||j>=m){
        //if any of the string finished then ans is 0
        return 0;
    }
    //if current state has already been computed
    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }
    ll res = 0;
    if(a[i]==b[j]){
        res = 1 + f(i+1,j+1,k);
    }
    else{
        if(k>0)
            res = 1 + f(i+1,j+1,k-1);
        res = max(res,f(i+1,j,k));
        res = max(res,f(i,j+1,k));
    }
    return dp[i][j][k] = res;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    ll k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    ll ans = f(0,0,k);
    cout<<ans<<endl;
    return 0;        
}
