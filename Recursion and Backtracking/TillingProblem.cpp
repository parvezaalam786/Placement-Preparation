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

int count1(int n,int m)
{
  int count[n+1];
  count[0] = 0;
  for(int i=1;i<=n;i++)
  {
    if(i>m)
      count[i] = (count[i-1]+count[i-m])%mod;
    else if(i==m)
      count[i] = 2;
    else
      count[i] = 1;     
  }
  return count[n];
}
//recursive 
int count2(int n,int m)
{
  if(n<=0)
    return 0;
  else if(n>=1 and n<m)
    return 1;
  else if(n==m)
    return 2;
  else
    return (count1(n-1,m)+count1(n-m,m))%mod;
}

int main()
{
    fast_io;
    ///input;
    ///output;
    int T;
    cin>>T;
    while(T--)
    {
      int n,m;
      cin>>n>>m;
      int ans = count1(n,m);
      cout<<ans<<endl;
    }
    return 0;
}