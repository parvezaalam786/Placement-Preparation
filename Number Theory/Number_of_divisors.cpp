#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL);
#define input freopen("Test.txt","r",stdin)
#define output freopen("Output.txt","w",stdout);
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define F(i,a,b) for(int i = a; i < b; i++)
#define MAX(a,b,c) max(a,max(b,c))
#define MIN(a,b,c) min(a,min(b,c))
#define pb push_back
#define eb emplace_back
#define inf 1000000000
const double pi = 3.141592653589793238460;
#define debug false
#define mod 1000000007


void solve()
{
    int T; cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        F(i,0,n) cin>>arr[i];

        map<int,int> m1;

        F(i,0,n)
        {
            for(int j=2;j*j<=arr[i];j++)
            {
                if(arr[i]%j==0)
                {
                    while(arr[i]%j==0)
                    {
                        if(m1.count(j))
                            m1[j] += 1;
                        else
                            m1[j] = 1;
                        arr[i] /= j;
                    }
                }
            }
            if(arr[i]>1)
            {
                if(m1.count(arr[i]))
                    m1[arr[i]] += 1;
                else
                    m1[arr[i]] = 1;
            }
        }
        ll ans = 1;
        for(auto i:m1)
        {
            ans = (ans*(i.second+1))%mod;
        }
        cout<<ans<<"\n";
        m1.clear();
    }

}

int main()
{
     // input; // output; // if(debug){watch_is();}
    fast_io;
    solve();   
    return 0;
}