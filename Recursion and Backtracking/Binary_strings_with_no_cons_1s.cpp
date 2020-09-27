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


int main()
{
    fast_io;
    ///input;
    ///output;
    int T,n;
    ll arr[91];
    arr[0] = 0;
    arr[1] = 2;
    arr[2] = 3;
    for(int i=3;i<=90;i++)
        arr[i] = arr[i-1]+arr[i-2];
    cin>>T;
    while(T--)
    {
        cin>>n;
        cout<<arr[n]<<endl;
    }
    return 0;
}