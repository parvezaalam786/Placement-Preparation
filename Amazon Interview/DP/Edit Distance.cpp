// https://www.interviewbit.com/problems/edit-distance/
/*
Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)
There are three operations:
    (i)   Insert a character to first string then we need to make (j-1) part of B equal to A : op1 = (i,j-1)+1
    (ii)  Delete a character from first string then we need to make (i-1) part of A equal to B : op2 = (i-1,j)+1
    (iii) Replace a character characters then both strings decrease by one letter and the cost will be 1 when the
          ith and jth characters are different else it will be 0 : op3 = (i-1,j-1) + (A[i] != B[j])

*/

int Solution::minDistance(string A, string B)
{
    int n1 = A.length();
    int n2 = B.length();
    int dp[n1 + 1][n2 + 1];

    for (int i = 0; i <= n2; i++)
        dp[0][i] = i; // cost of making i length string(B) from null string(A)
    for (int i = 0; i <= n1; i++)
        dp[i][0] = i; // cost of making i length string(A) from null string(B)

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            int op1 = dp[i][j - 1] + 1; // insert
            int op2 = dp[i - 1][j] + 1; // delete
            int op3 = dp[i - 1][j - 1] + (A[i - 1] != B[j - 1]); //replace

            dp[i][j] = min(op1, min(op2, op3));
        }
    }
    return dp[n1][n2];

}
