// https://www.interviewbit.com/problems/snake-ladder-problem/

map<int, int> mp;

int BFS()
{
    bool visited[101];
    memset(visited, false, sizeof(visited));

    queue<int> que;
    que.push(1);
    visited[1] = true;

    int steps = 0;
    while (!que.empty())
    {
        int n = que.size();

        for (int i = 0; i < n; i++)
        {
            int curr = que.front();
            que.pop();
            if (curr == 100)
                return steps;
            for (int i = 1; i <= 6; i++)
            {
                if (curr + i <= 100)
                {
                    if (mp.count(curr + i) == 0)
                    {
                        if (!visited[curr + i])
                        {
                            visited[curr + i] = true;
                            que.push(curr + i);
                        }
                    }
                    else
                    {
                        if (!visited[mp[curr + i]])
                        {
                            visited[mp[curr + i]] = true;
                            que.push(mp[curr + i]);
                        }
                    }
                }
            }
        }
        steps++;
    }
    return -1;
}

int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B)
{
    mp.clear();
    for (auto &x : A)
    {
        mp[x[0]] = x[1];
    }
    for (auto &x : B)
    {
        mp[x[0]] = x[1];
    }
    return BFS();
}
