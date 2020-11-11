// https://leetcode.com/problems/01-matrix/

/*
It is basically a variation of multi-source bfs traversal
*/

#define inf 1000000000
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        int N = mat.size();
        int M = mat[0].size();
        int total_nodes = N * M;
        vector<int> adj[total_nodes];
        // We will be adding edges in right and down fashion
        int k = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (i == N - 1) // standing at the last row so no need to join down node
                {
                    if (j != M - 1) // if not at the right most node of last row
                    {
                        adj[k].push_back(k + 1);
                        adj[k + 1].push_back(k);
                    }
                }
                else if (j == M - 1) //last node in current row, then adding only down cell
                {
                    adj[k].push_back(k + M);
                    adj[k + M].push_back(k);
                }
                else
                {
                    adj[k].push_back(k + 1);
                    adj[k + 1].push_back(k);
                    adj[k].push_back(k + M);
                    adj[k + M].push_back(k);
                }
                k++;
            }
        }
        vector<vector<int>> dist(N, vector<int>(M));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
                dist[i][j] = inf;
        }

        queue<int> que;
        k = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (mat[i][j] == 0) // in case of 1 replace 0 with 1
                {
                    que.push(k);
                    dist[k / M][k % M] = 0;
                }
                k++;
            }
        }

        bool visited[total_nodes];
        memset(visited, false, sizeof(visited));

        if (!que.empty())
            visited[que.front()] = 1;

        while (!que.empty())
        {
            int curr = que.front();
            que.pop();
            for (auto node : adj[curr])
            {
                if (visited[node] == 0)
                {
                    visited[node] = 1;
                    dist[node / M][node % M] = min(dist[node / M][node % M], dist[curr / M][curr % M] + 1);
                    que.push(node);
                }
            }
        }
        return dist;
    }
};