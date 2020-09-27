#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define int long long
#define inf 1e9
#define mod 1000000007

vector<int> ar[100];
vector<int> res;
int in[100];

void kahn(int n)
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int curr = q.front();
        res.push_back(curr);
        q.pop();
        for (int node : ar[curr])
        {
            in[node]--;
            if (in[node] == 0)
                q.push(node);
        }
    }
    cout << "Topo sort .. : ";
    for (int i : res)
        cout << i << " ";
}

void solve()
{
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        ar[x].push_back(y);
        in[y]++;
    }
    kahn(n);
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

/*
9 10
1 2
3 4
1 8
2 9
2 5
4 5
4 8
5 9
5 7
6 7

Topo sort .. : 1 3 6 2 4 5 8 9 7
*/
