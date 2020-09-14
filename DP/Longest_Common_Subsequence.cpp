/*
https://leetcode.com/problems/longest-common-subsequence/
*/

//Top Down
class Solution {
public:

    int dp[1005][1005];

    int LCS(string& s1, string& s2, int n, int m)
    {
        if (n == 0 or m == 0)
            return 0;

        if (dp[n][m] != -1)
            return dp[n][m];

        if (s1[n - 1] == s2[m - 1])
            return dp[n][m] = 1 + LCS(s1, s2, n - 1, m - 1);

        else
        {
            return dp[n][m] = max(LCS(s1, s2, n - 1, m), LCS(s1, s2, n, m - 1));
        }
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        memset(dp, -1, sizeof(dp));
        int ans = LCS(text1, text2, text1.length(), text2.length());
        return ans;
    }
};

//Bottom up
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2)
    {
        int n = s1.length();
        int m = s2.length();
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 or j == 0)
                    dp[i][j] = 0;
                else if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};