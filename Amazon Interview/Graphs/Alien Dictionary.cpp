/*
Success is Never Owned, It’s Rented, and the Rent is Due EveryDay!!
Love the music of silence.
*/
// https://practice.geeksforgeeks.org/problems/alien-dictionary/1

/*
The idea here is to compare the adjacent strings. The first index where the characters mismatched add
an edge and increase the in degree of later one. Now after that print the inorder traversal of the graph.
*/

string findOrder(string dict[], int N, int K)
{
    vector<int> adj[30];
    int in[30];
    for (int i = 0; i < 30; i++)
        in[i] = 0;
    for (int i = 0; i < N - 1; i++)
    {
        int n1 = dict[i].length();
        int n2 = dict[i + 1].length();

        for (int j = 0; j < min(n1, n2); j++)
        {
            if (dict[i][j] != dict[i + 1][j])
            {
                adj[dict[i][j] - 'a'].push_back(dict[i + 1][j] - 'a');
                in[dict[i + 1][j] - 'a']++;
                break;
            }
        }
    }
    queue<int> que;
    for (int i = 0; i < K; i++)
        if (in[i] == 0)
            que.push(i);

    string ans = "";
    while (!que.empty())
    {
        int curr = que.front();
        que.pop();
        ans.push_back(curr + 'a');
        for (auto i : adj[curr])
        {
            in[i]--;
            if (in[i] == 0)
                que.push(i);
        }
    }
    return ans;
}