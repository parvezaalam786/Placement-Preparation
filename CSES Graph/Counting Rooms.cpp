/*
Success is Never Owned, It’s Rented, and the Rent is Due EveryDay!!
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1001;

int n, m;
char mat[maxn][maxn];

/*
Possible movements from (x,y)
(x,y+1),(x,y-1),(x-1,y),(x+1,y)
*/
void dfs(int i, int j)
{
    mat[i][j] = '#';
    if (j + 1 < m and mat[i][j + 1] == '.')
        dfs(i, j + 1);
    if (j - 1 >= 0 and mat[i][j - 1] == '.')
        dfs(i, j - 1);
    if (i - 1 >= 0 and mat[i - 1][j] == '.')
        dfs(i - 1, j);
    if (i + 1 < n and mat[i + 1][j] == '.')
        dfs(i + 1, j);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    int rooms = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == '.')
            {
                dfs(i, j);
                rooms++;
            }
        }
    }
    cout << rooms << "\n";
    return 0;
}