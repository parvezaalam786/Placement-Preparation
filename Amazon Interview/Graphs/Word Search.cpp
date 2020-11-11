/*
https://leetcode.com/problems/word-search/

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells,
where "adjacent" cells are horizontally or vertically neighboring.

=>The same letter cell may not be used more than once.

*/
class Solution {
public:
    int dx[4] = {0, -1, 1, 0};
    int dy[4] = { -1, 0, 0, 1};

    bool isvalid(int n, int m, int i, int j, vector<vector<bool>>& visited)
    {
        if (i >= 0 and i<n and j >= 0 and j < m and visited[i][j] == false)
            return true;
        return false;
    }

    bool WordSearch(vector<vector<char>>& board, string &word, int n, int m, int curr_i, int curr_j, int idx, vector<vector<bool>>& visited)
    {
        if (idx == word.length())
            return true;
        visited[curr_i][curr_j] = true;

        for (int k = 0; k < 4; k++)
        {
            if (isvalid(n, m, curr_i + dx[k], curr_j + dy[k], visited) and board[curr_i + dx[k]][curr_j + dy[k]] == word[idx])
            {
                if (WordSearch(board, word, n, m, curr_i + dx[k], curr_j + dy[k], idx + 1, visited))
                    return true;
            }

        }

        visited[curr_i][curr_j] = false;
        return false;
    }


    bool exist(vector<vector<char>>& board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (WordSearch(board, word, n, m, i, j, 1, visited))
                        return true;
                }
            }
        }
        return false;
    }
};