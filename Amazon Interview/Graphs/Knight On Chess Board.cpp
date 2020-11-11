// https://www.interviewbit.com/problems/knight-on-chess-board/
#define ff first
#define ss second
int dx[] = { -1, -2, -2, -1, 1, 2, 1, 2};
int dy[] = { -2, -1, 1, 2, -2, -1, 2, 1};
int Solution::knight(int A, int B, int C, int D, int E, int F)
{
    bool visited[A + 1][B + 1];
    memset(visited, false, sizeof(visited));

    int dist[A + 1][B + 1];
    memset(dist, 0, sizeof(dist));

    queue<pair<pair<int, int>, int>> que;
    que.push({{C, D}, 0});
    visited[C][D] = true;
    dist[C][D] = 0;

    while (!que.empty())
    {
        auto curr = que.front();
        que.pop();
        int x = curr.ff.ff;
        int y = curr.ff.ss;
        int d = curr.ss;

        for (int i = 0; i < 8; i++)
        {
            if (x + dx[i] > 0 and x + dx[i] <= A and y + dy[i] > 0 and y + dy[i] <= B and visited[x + dx[i]][y + dy[i]] == false)
            {
                visited[x + dx[i]][y + dy[i]] = true;
                dist[x + dx[i]][y + dy[i]] = d + 1;
                que.push({{x + dx[i], y + dy[i]}, d + 1});
            }
        }
        if (visited[E][F])
            return dist[E][F];
    }
    return -1;
}
