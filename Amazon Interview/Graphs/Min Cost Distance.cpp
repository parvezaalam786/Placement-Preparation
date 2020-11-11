// User function template for C++

// grid : given n*n grid
// n : size of the square grid
/*
This problem cannot be solved by dp (as it was in case when right down and diagonal movements were allowed)
This will be solved by using Dijkstra on 2D matrix
*/

#define pii pair<int,int>
bool isvalid(int x, int y, int n)
{
    if (x >= 0 and x<n and y >= 0 and y < n)
        return true;
    return false;
}

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int shortest(vector<vector<int> > &grid, int n)
{
    int dist[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            dist[i][j] = 1000000000;
    }

    set<pair<int, pii>> pq;

    pq.insert({0, {0, 0}});
    dist[0][0] = 0;
    while (!pq.empty())
    {
        auto it = *pq.begin();

        int curr_cost = it.first;
        int curr_x = it.second.first;
        int curr_y = it.second.second;
        pq.erase(pq.begin());


        for (int i = 0; i < 4; i++)
        {
            if (isvalid(curr_x + dx[i], curr_y + dy[i], n))
            {
                if (dist[curr_x + dx[i]][curr_y + dy[i]] > curr_cost + grid[curr_x + dx[i]][curr_y + dy[i]])
                {
                    dist[curr_x + dx[i]][curr_y + dy[i]] = curr_cost + grid[curr_x + dx[i]][curr_y + dy[i]];

                    pq.insert({dist[curr_x + dx[i]][curr_y + dy[i]], {curr_x + dx[i], curr_y + dy[i]}});
                }
            }
        }
    }

    return dist[n - 1][n - 1];
}