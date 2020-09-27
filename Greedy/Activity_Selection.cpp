#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL);
#define input freopen("Test.txt","r",stdin)
#define output freopen("Output.txt","w",stdout);
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define F(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define eb emplace_back
#define inf 1000000000
const double pi = 3.141592653589793238460;
#define debug false
#define mod 1000000007

struct work
{
    int a,b;
};
work arr[10010];

bool cmp(work x,work y)
{
    if(x.b==y.b)
        return x.a<y.a;
    return x.b<y.b;   
}
void solve()
{
    int T; cin>>T;
    while(T--)
    {
        int n; cin>>n;
        int s,e;
        F(i,0,n)
        {
            cin>>s>>e;
            arr[i].a = s;
            arr[i].b = e;
        }
        sort(arr,arr+n,cmp);

        int cur = 0;
        int cnt = 0;
        F(i,0,n)
        {
            if(arr[i].a>=cur)
            {
                cur = arr[i].b;
                cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
}

int main()
{
    // fast_io; // input; // output; // if(debug){watch_is();}
    solve();   
    return 0;
}