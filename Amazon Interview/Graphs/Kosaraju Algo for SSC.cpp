/*
Success is Never Owned, It’s Rented, and the Rent is Due EveryDay!!
Love the music of silence.
*/

/*
(i) Create transposed graph of the given graph
(ii) Calculate the finishing order of all the vertices by running a dfs on the original graph
(iii) Now start the dfs in the transposed graph with source as last vertex in the finishing order
    array till all the vertices are not visited
(iv) After each dfs traversal in the transposed graph we will have the strongly connected component
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

vector<int> adj[1001]; // adjacency list for graph
vector<int> tr[1001]; // adjacency list for transposed graph
vector<int> order; // stores the last finishing order of the vertices in the dfs traversal
vector<int> SSC;
int visited[1001];

void dfs(int node)
{
    visited[node] = 1;
    for (int child : adj[node])
    {
        if (visited[child] == 0)
            dfs(child);
    }
    order.push_back(node);
}

void dfs1(int node)
{
    visited[node] = 1;
    for (auto child : tr[node])
    {
        if (visited[child] == 0)
        {
            dfs1(child);
        }
    }
    SSC.push_back(node);
}

void solve()
{
    int n, a, b, m, T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            adj[i].clear();
            tr[i].clear();
            visited[i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            tr[b].push_back(a);
        }

        for (int i = 1; i <= n; i++)
            if (visited[i] == 0)
                dfs(i);

        for (int i = 1; i <= n; i++)
            visited[i] = 0;

        for (int i = 1; i <= n; i++)
        {
            if (visited[order[n - i]] == 0)
            {
                SSC.clear();
                dfs1(order[n - i]);

                cout << "dfs1() called from " << order[n - i] << " and printing SSC" << "\n";
                for (int node : SSC)
                {
                    cout << node << " ";
                }
                cout << "\n";
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

/*
1
7 8
1 2
2 3
3 1
4 3
7 4
7 5
5 6
6 7

output:

dfs1() called from 5 and printing SSC
6 7 5
dfs1() called from 4 and printing SSC
4
dfs1() called from 1 and printing SSC
2 3 1

*/
