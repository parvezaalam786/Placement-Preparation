#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007

const int maxn = 100010;
int timer;
int S[maxn], T[maxn], FT[2 * maxn];
vector<int> adj[maxn];

void dfs(int node, int par)
{
    S[node] = timer;
    FT[timer] = node;
    timer++;

    for (int child : adj[node])
    {
        if (child != par)
        {
            dfs(child, node);
        }
    }
    T[node] = timer;
    FT[timer] = node;
    timer++;
}

void solve()
{
    int n, a, b;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    timer = 1;
    dfs(1, -1);

    cout << "S = { ";
    for (int i = 1; i <= n; i++)
        cout << S[i] << " , ";
    cout << " }" << "\n";

    cout << "T = { ";
    for (int i = 1; i <= n; i++)
        cout << T[i] << " , ";
    cout << " }" << "\n";

    cout << "FT = { ";
    for (int i = 1; i <= 2 * n; i++)
        cout << FT[i] << " , ";
    cout << " }" << "\n";

}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

/*
input:
4
1 2
1 3
3 4
op:
S = { 1 , 2 , 4 , 5 ,  }
T = { 8 , 3 , 7 , 6 ,  }
FT = { 1 , 2 , 2 , 3 , 4 , 4 , 3 , 1 ,  }
*/