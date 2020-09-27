#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define int long long
#define inf 1e9
#define mod 1000000007

int phi[1000001];
void init(int maxN)
{
    for (int i = 1; i <= maxN; i++)
        phi[i] = i;

    for (int i = 2; i <= maxN; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= maxN; j += i)
            {
                phi[j] /= i;
                phi[j] *= (i - 1);
            }
        }
    }
}
void solve()
{
    init(1000000);
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        cout << phi[n] << "\n";
    }
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
