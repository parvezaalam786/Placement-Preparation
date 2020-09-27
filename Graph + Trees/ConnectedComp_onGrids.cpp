#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007

int N, M;
bool vis[1001][1001];
int arr[1001][1001];
int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(int x, int y)
{
    if (x < 1 || x > N || y < 1 || y > M)
        return false;
    if (vis[x][y] == true || arr[x][y] == 0)
        return false;
    return true;
}

void dfs(int x, int y)
{
    vis[x][y] = 1;
    // cout << x << " " << y << "\n";
    for (int i = 0; i < 4; i++)
    {
        if (isValid(x + dx[i], y + dy[i]))
            dfs(x + dx[i], y + dy[i]);
    }

}
void solve()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> arr[i][j];
        }
    }
    int cc = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (vis[i][j] == 0 and arr[i][j] == 1)
            {
                dfs(i, j);
                cc++;
            }
        }
    }
    cout << "Connected Components = " << cc << "\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

/*
6 6
0 0 1 0 1 1
0 1 1 0 0 1
0 1 0 0 0 0
1 0 1 1 0 0
0 0 0 1 0 0
0 1 1 0 1 1

ans = 6

*/