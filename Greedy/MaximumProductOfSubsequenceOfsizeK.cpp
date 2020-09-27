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
#define inf 1e9
const double pi = 3.141592653589793238460;
#define debug false
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define mod 1000000007
int min(int x,int y){ if(x<y) return x; return y; }
int max(int x,int y){ if(x<y) return y; return x; }


void solve()
{
	int T;
    cin>>T;
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        F(i,0,n) cin>>arr[i];
        sort(arr,arr+n);

        int ans = 1LL;

        if(arr[n-1]<0 and k%2==1)
        {
            for(int i=0;i<k;i++)
            {
                ans = (ans*arr[n-i-1])%mod;
            }
        }
        else
        {
            int i = 0,j = n-1;
            while(k>0)
            {
                if(k>1)
                {
                    if(arr[i]*arr[i+1]>arr[j]*arr[j-1])
                    {
                        ans = ((arr[i]*arr[i+1])%mod)*(ans%mod)%mod;
                        i+=2;
                        k-=2;
                    }
                    else
                    {
                        ans = ((arr[j]%mod)*(ans%mod))%mod;
                        j--;
                        k--;
                    }
                }
                else
                {
                    ans = ((arr[j]%mod)*(ans%mod))%mod;
                    j--;
                    k--;
                }   
            }
        }
        ans = (ans+mod)%mod;
        cout<<ans<<"\n";
    }
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif

	// if(debug){watch_is();}
	solve();
	return 0;
}