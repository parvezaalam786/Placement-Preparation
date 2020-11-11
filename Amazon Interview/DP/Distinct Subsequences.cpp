// https://www.interviewbit.com/problems/distinct-subsequences/
/*
The idea here is:
At the ith character in s1 and jth character in s2:
    There are two case:
        (a) s1[i] = s2[j]
        (b) s1[i] != s2[j]

    Now by making the decisions:
    for case(a): we will take the ith character and move on , or will not take the ith character
        ans = fun(i+1,j+1) + fun(i+1,j)
    for case(b): we have to move forward
        ans = fun(i+1,j)
*/


int dp[705][705];

int fun(string &s1, string &s2, int i, int j)
{
    if (j == s2.length())
        return 1;
    if (i == s1.length())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int &ans = dp[i][j];

    if (s1[i] != s2[j])
        return ans = fun(s1, s2, i + 1, j);
    else
        return ans = fun(s1, s2, i + 1, j + 1) + fun(s1, s2, i + 1, j);
}

int Solution::numDistinct(string A, string B)
{
    memset(dp, -1, sizeof(dp));
    return fun(A, B, 0, 0);
}
