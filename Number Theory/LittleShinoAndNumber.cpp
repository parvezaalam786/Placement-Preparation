// You are given an integer array A of size x denoting the prime powers of an integer N.
// Ai denotes the power of ith prime in the prime factorization of N.
// To make it more clear, A1 will denote the power of 2 in the prime factorization of N A2 will denote the power of 3 in the prime factorization of N and so on. Consider a number P.
// P equals to the product of all the divisors of N You have to find the number of divisors of P.
// Output it modulo 109+7.
// Little shino and number hackerearth

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
 	int x;
    cin>>x;
    vector<int> v1(x);
    int divisors = 1;
    for(int i=0;i<x;i++)
    {
        cin>>v1[i];
        divisors = (divisors*(v1[i]+1))%mod;
    }
    int ans = 1;
    for(int i=0;i<x;i++)
    {
        v1[i] = (divisors*v1[i])%mod;
        v1[i] = (v1[i]*500000004)%mod;
        ans = (ans*(v1[i]+1))%mod;
        // ans = (ans*((v1[i])*(divisors/2)+1))%mod;
    }

    // for(auto i:v1)
    //     cout<<i<<" ";
    cout<<ans<<"\n";
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