// https://www.interviewbit.com/problems/repeating-subsequence/

/*
Given a string A, find length of the longest repeating sub-sequence such that the two subsequence
don’t have same string character at same position,

i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

NOTE: Sub-sequence length should be greater than or equal to 2.
*/

/*
The idea here is same as finding the LCS between two strings. The only change is in the condition where
the ith and jth characters are same , we will check if (s1[i-1] == s1[j-1] && i != j)
*/

int Solution::anytwo(string s1)
{
    int n = s1.length();

    int dp[n + 1][n + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s1[j - 1] and i != j)
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return (dp[n][n] >= 2);
}
