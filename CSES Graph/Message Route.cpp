/*
Success is Never Owned, It’s Rented, and the Rent is Due EveryDay!!
*/
#include<bits/stdc++.h>
using namespace std;
/*
Minimum distance and path => use bfs
*/

const int maxn = 100010;
vector<int> adj[maxn];
bool visited[maxn];
int dist[maxn];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i = 0; i < maxn; i++)
    {
        dist[i] = 0;
        visited[i] = false;
    }
    int n, m;
    cin >> n >> m;

    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto x : adj[node])
        {
            if (visited[x] == false)
            {
                visited[x] = true;
                dist[x] = dist[node] + 1;
                q.push(x);
            }
        }
    }
    if (visited[n] == false)
        cout << "IMPOSSIBLE";
    else
    {
        cout << dist[n] + 1 << "\n";
        vector<int> ans;
        int d = dist[n];
        int node = n;
        ans.push_back(n);

        while (d > 1)
        {
            for (auto i : adj[node])
            {
                if (dist[i] == d - 1)
                {
                    node = i;
                    ans.push_back(i);
                    d--;
                    break;
                }
            }
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
    }

    return 0;
}