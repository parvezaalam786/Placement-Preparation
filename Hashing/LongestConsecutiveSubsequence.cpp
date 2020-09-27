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

int LongestConsecutiveSubsequence(int arr[],int n)
{
    unordered_set<int> s;
    for(int i=0;i<n;i++)
        s.insert(arr[i]);
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(s.find(arr[i]-1)!=s.end())
            continue;
        else
        {
            int cnt = 0;
            int x = arr[i];
            while(s.find(x)!=s.end())
            {
                x++;cnt++;
            }
            ans = max(ans,cnt);
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int ans = LongestConsecutiveSubsequence(arr,n);
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