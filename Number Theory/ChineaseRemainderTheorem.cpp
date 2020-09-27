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

int inv(int a,int m)
{
    int m0 = m,t,q;
    int x0 = 0, x1 = 1;
    if(m==1)
        return 0;
    // applying extended euclid algorithm
    while(a>1)
    {
        q = a/m;
        t = m;
        m = a%m,a = t;
        t = x0;
        x0 = x1-q*x0;
        x1 = t;
    }
    if(x1<0)
        x1 += m0;
    return x1;
}

int findMinX(int num[],int rem[],int k)
{
    int prod = 1;
    for(int i=0;i<k;i++)
    {
        prod *= num[i];
    }
    int result = 0;
    for(int i=0;i<k;i++)
    {
        int pp = prod/num[i];
        result += rem[i]*inv(pp,num[i])*pp;
    }
    return result%prod;
}
void solve()
{
 	int num[] = {3, 4, 5}; 
    int rem[] = {2, 3, 1}; 
    int k = sizeof(num)/sizeof(num[0]); 
    cout << "x is " << findMinX(num, rem, k);
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