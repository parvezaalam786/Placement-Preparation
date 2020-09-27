#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define int long long
#define inf 1e9
#define mod 1000000007

vector<int> adj[1001];
const int maxN = 10;
int level[1001], LCA[1001][maxN + 1];

void dfs(int node, int lvl, int par)
{
    level[node] = lvl;
    LCA[node][0] = par;
    for (int child : adj[node])
    {
        if (child != par)
        {
            dfs(child, lvl + 1, node);
        }
    }
}

void init(int n)
{
    dfs(1, 0, -1);
    for (int i = 1; i <= maxN; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (LCA[j][i - 1] != -1)
            {
                int par = LCA[j][i - 1];
                LCA[j][i] = LCA[par][i - 1];
            }
        }
    }
}

int getLCA(int a, int b)
{
    if (level[b] < level[a])
        swap(a, b);
    int d = level[b] - level[a];
    while (d > 0)
    {
        int i = log2(d);
        b = LCA[b][i];
        d -= 1 << i;
    }
    if (a == b)
        return a;
    for (int i = maxN; i >= 0; i--)
    {
        if (LCA[a][i] != -1 and (LCA[a][i] != LCA[b][i]))
        {
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }
    return LCA[a][0];
}

int getDist(int a, int b)
{
    int lca = getLCA(a, b);
    return level[a] + level[b] - 2 * level[lca];
}

void solve()
{
    int n, q, a, b;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= maxN; j++)
        {
            LCA[i][j] = -1;
        }
    }
    for (int i = 1; i < n; i++)
    {

        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    init(n);

    cin >> q;
    while (q--)
    {
        cin >> a >> b;
        cout << getDist(a, b) << "\n";
    }

}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
/*
input tree:
10
1 2
1 3
2 6
2 9
3 4
6 8
9 5
4 10
4 7
4
1 1
1 4
6 3
8 5
output:
0
2
3
4

input tree:
10
1 2
1 3
2 6
2 9
3 4
4 7
4 10
6 8
9 5
4
1 2
1 5
10 7
2 8
output:
1
3
2
2


*/