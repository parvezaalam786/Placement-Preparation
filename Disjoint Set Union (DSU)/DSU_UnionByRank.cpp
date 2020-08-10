#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define int long long
#define endl "\n"
#define pb push_back
#define inf 1e9
const double pi = 3.141592653589793238460;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define mod 1000000007

const int maxn = 100005;

int par[maxn];
int Rank[maxn];
int find(int a)
{
    if (par[a] < 0)
        return a;
    return par[a] = find(par[a]);
}

void Union(int a, int b) ///Merge in union by rank
{
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (Rank[a] > Rank[b])
    {
        par[b] = a;
        Rank[a] += Rank[b];
    }
    else
    {
        par[a] = b;
        Rank[b] += Rank[a];
    }
}

bool check(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return true;
    return false;
}

void solve()
{
    for (int i = 1; i <= 10; i++)
        par[i] = -i, Rank[i] = 1;
    Union(1, 2);
    Union(2, 3);
    Union(2, 4);
    Union(5, 6);
    Union(6, 7);
    Union(7, 8);
    Union(9, 10);

    int a, b;
    for (int i = 0; i < 5; i++)
    {
        cin >> a >> b;
        cout << check(a, b) << "\n";
    }
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
