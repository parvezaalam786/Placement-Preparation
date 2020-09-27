#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define int long long
#define inf 1e9
#define mod 1000000007

vector<int> adj[100010];
int level[100010];
bool visited[100010];
int par[100010];
void bfs(int src)
{
    par[src] = src;
    level[src] = 1;
    queue<int> que;
    visited[src] = true;
    que.push(src);
    while (!que.empty())
    {
        int node = que.front();
        que.pop();
        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                visited[i] = true;
                que.push(i);
                level[i] = level[node] + 1;
                par[i] = node;
            }
        }
    }
}

int LCA(int a, int b)
{
    if (level[a] > level[b])
        swap(a, b);
    int d = level[b] - level[a];
    while (d > 0)
    {
        b = par[b];
        d--;
    }
    if (a == b) return a;
    while (par[a] != par[b])
    {
        a = par[a];
        b = par[b];
    }
    return par[a];
}

void solve()
{
    int N, u, v;
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1); // setting the levels to each node

    for (int i = 1; i <= N; i++)
        cout << level[i] << " ";
    cout << "\n";
    int q;
    cin >> q;
    while (q--)
    {
        cin >> u >> v;
        cout << LCA(u, v) << "\n";
    }
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

/*
Input tree and queries:
10
1 2
2 3
3 4
4 5
3 6
6 7
1 8
8 9
9 10
5
4 7
8 10
3 9
2 8
7 10
Output:
3
8
1
1
1
*/