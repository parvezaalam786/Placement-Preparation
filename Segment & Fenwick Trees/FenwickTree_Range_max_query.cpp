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

int arr[100010];
int BIT[100010] = {0};

// Range max sum update - logn time
void update(int i, int val, int N)
{
    while (i <= N)
    {
        BIT[i] = max(BIT[i], val);
        i = i + (i & (-i));
    }
}
// max till ith index  - logn time
int query(int i)
{
    int ans = 0;
    while (i > 0)
    {
        ans = max(BIT[i], ans);
        i -= (i & (-i));
    }
    return ans;
}

void solve()
{
    int n; cin >> n;
    F(i, 1, n + 1)
    {
        cin >> arr[i];
        update(i, arr[i], n);
    }
    update(3, 10, n);
    int q, idx;
    cin >> q;
    while (q--)
    {
        cin >> idx;
        cout << query(idx) << "\n";
    }
}

int main()
{
    // input; // output; // if(debug){watch_is();}
    fast_io;
    solve();
    return 0;
}

/*
5
5 4 1 7 3
5
1 2 3 4 5
5
5
10
10
10

*/