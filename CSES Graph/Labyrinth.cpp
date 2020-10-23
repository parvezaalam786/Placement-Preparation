/*
Success is Never Owned, It’s Rented, and the Rent is Due EveryDay!!
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007
#define ff first
#define ss second

/*
Note: Whenever distance is asked in the problem think it in terms of bfs as it works in most of the cases.

The idea here is to use bfs and maintain visited array and distance array.
If the visited position of 'B' is true:
    print("YES")
    print(distance of 'B')
    backtrack from 'B' to 'A' to print the path
else:
    print("NO")
*/


const int maxn = 1010;
int n, m;
vector<vector<char>> adj(maxn, vector<char>(maxn));
vector<vector<int>> dist(maxn, vector<int>(maxn, 0LL));
vector<vector<bool>> visited(maxn, vector<bool>(maxn, false));
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isvalid(int x, int y)
{
    if (x >= 0 and x<n and y >= 0 and y < m and (adj[x][y] == '.' or adj[x][y] == 'B') and (visited[x][y] == false))
        return true;
    return false;
}


void bfs(int x, int y)
{
    queue<pair<int, int>> que;
    que.push({x, y});
    visited[x][y] = true;
    while (!que.empty())
    {
        auto curr = que.front();
        que.pop();

        for (int i = 0; i < 4; i++)
        {
            if (isvalid(curr.ff + dx[i], curr.ss + dy[i]))
            {
                dist[curr.ff + dx[i]][curr.ss + dy[i]] = dist[curr.ff][curr.ss] + 1;
                visited[curr.ff + dx[i]][curr.ss + dy[i]] = true;
                que.push({curr.ff + dx[i], curr.ss + dy[i]});
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    int x1, y1, x2, y2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];
            if (adj[i][j] == 'A')
            {
                x1 = i; y1 = j;
            }
            if (adj[i][j] == 'B')
            {
                x2 = i; y2 = j;
            }
        }
    }

    bfs(x1, y1);
    /*
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << dist[i][j] << " ";
            cout << "\n";
        }
    */
    if (visited[x2][y2] == false)
        cout << "NO" << "\n";
    else
    {
        cout << "YES" << "\n";
        cout << dist[x2][y2] << "\n";
        int d = dist[x2][y2];
        string path = "";
        //Backtracking
        while (d > 0)
        {
            if (y2 - 1 >= 0 and (adj[x2][y2 - 1] == 'A' or adj[x2][y2 - 1] == '.') and dist[x2][y2 - 1] == d - 1)
            {
                path += 'R';
                y2--;
            }
            else if (y2 + 1 < m and (adj[x2][y2 + 1] == 'A' or adj[x2][y2 + 1] == '.') and dist[x2][y2 + 1] == d - 1)
            {
                path += 'L';
                y2++;
            }
            else if (x2 - 1 >= 0 and (adj[x2 - 1][y2] == 'A' or adj[x2 - 1][y2] == '.') and dist[x2 - 1][y2] == d - 1)
            {
                path += 'D';
                x2--;
            }
            else if (x2 + 1 < n and (adj[x2 + 1][y2] == 'A' or adj[x2 + 1][y2] == '.') and dist[x2 + 1][y2] == d - 1)
            {
                path += 'U';
                x2++;
            }
            d--;
        }
        reverse(path.begin(), path.end());
        cout << path << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
