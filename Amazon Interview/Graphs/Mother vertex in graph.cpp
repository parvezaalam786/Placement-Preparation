/*
Success is Never Owned, It’s Rented, and the Rent is Due EveryDay!!
Love the music of silence.
*/
// https://practice.geeksforgeeks.org/problems/mother-vertex/1/?track=amazon-graphs&batchId=192#
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

const int maxn = 100010;
vector<int> adj[maxn];
bool visited[maxn];

int dfs(int src)
{
    visited[src] = 1;
    for (auto i : adj[src])
    {
        if (visited[i] == false)
            dfs(i);
    }
    return src;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    int last_finished = -1;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            last_finished = dfs(i);
        }
    }

    memset(visited, false, sizeof(visited));

    dfs(last_finished);

    bool is_mother_vertex = true;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            is_mother_vertex = false;
            break;
        }
    }
    if (is_mother_vertex)
        cout << last_finished << " is mother vertex." << "\n";
    else
        cout << "No mother vertex found" << "\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

/*
7 8
1 2
2 3
4 2
6 4
5 6
5 7
1 7
6 1

5 is mother vertex.
*/