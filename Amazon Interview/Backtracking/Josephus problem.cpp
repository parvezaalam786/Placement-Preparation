/*
Success is Never Owned, It’s Rented, and the Rent is Due EveryDay!!
Love the music of silence.
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007
#define ff first
#define ss second
#define deb(x) cout<<#x<<" = "<<x
#define all(x) (x).begin(),(x).end()

void fun(vector<int> v, int k, int idx, int &ans)
{
    if (v.size() == 1)
    {
        ans = v[0];
        return;
    }
    idx = (idx + k) % v.size();
    v.erase(idx + v.begin());
    fun(v, k, idx, ans);
    return;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = i + 1;
    }
    int ans;
    fun(v, k - 1, 0, ans);
    cout << ans << "\n";

}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
/*
40 7
=>24

5 2
=> 3
*/