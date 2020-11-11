/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1};
bool isvalid(int x, int y, int N, int M)
{
    return (x >= 0 and x<N and y >= 0 and y < M);
}
bool visited[101][101];
void dfs(vector<int>* &A, int i, int j, int N, int M)
{
    visited[i][j] = true;

    for (int k = 0; k < 8; k++)
    {
        if (isvalid(i + dx[k], j + dy[k], N, M) and A[i + dx[k]][j + dy[k]] == 1 and visited[i + dx[k]][j + dy[k]] == 0)
        {
            dfs(A, i + dx[k], j + dy[k], N, M);
        }
    }
}

int findIslands(vector<int> A[], int N, int M) {

    memset(visited, false, sizeof(visited));

    int islands = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (A[i][j] == 1 and visited[i][j] == false)
            {
                islands++;
                dfs(A, i, j, N, M);
            }
        }
    }
    return islands;

}
