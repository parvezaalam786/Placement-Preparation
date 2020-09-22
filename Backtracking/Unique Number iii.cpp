/*
Chase excellence, rating will come automatically.
*/
#include<bits/stdc++.h>
using namespace std;



/*
https://leetcode.com/problems/unique-paths-iii/

The idea here is to use backtracking along with dfs on matrix. We start from the source and move in all the four directions
and if we reach the destination we count the answer.
*/
int dfs(vector<vector<int>>& grid, int x, int y, int zero)
{
    if (x<0 or y<0 or x >= grid.size() or y >= grid[0].size() or grid[x][y] == -1)
        return 0;
    if (grid[x][y] == 2)
        return (zero == -1); // because in the grid we have to count 1 too so if have counted all the zeros then we need to consider the 1 also
    zero--;
    grid[x][y] = -1;
    int res = dfs(grid, x - 1, y, zero) + dfs(grid, x + 1, y, zero) + dfs(grid, x, y - 1, zero) + dfs(grid, x, y + 1, zero);

    grid[x][y] = 0;
    zero++;
    return res;
}

int uniquePathsIII(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int zero = 0, x = 0, y = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 0)
                zero++;
            if (grid[i][j] == 1)
            {
                x = i;
                y = j;
            }
        }
    }

    return dfs(grid, x, y, zero);
}

void solve()
{
    vector<vector<int>> grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}};
    cout << uniquePathsIII(grid);
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
