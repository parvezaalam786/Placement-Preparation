// Consider a row of n coins of values v1 . . . vn, where n is even. We play a game against an opponent by alternating turns.
//  In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and 
//  receives the value of the coin. Determine the maximum possible amount of money we can definitely win if we move first.

#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int optimalStrategyOfGame(int arr[],int i,int j)
{
    if(i>j)
        return 0;
    if(i+1==j)
        return max(arr[i],arr[j]);
    if(dp[i][j]!=-1)
        return dp[i][j];

    int res1 = arr[i]+min(optimalStrategyOfGame(arr,i+2,j),optimalStrategyOfGame(arr,i+1,j-1));
    int res2 = arr[j]+min(optimalStrategyOfGame(arr,i,j-2),optimalStrategyOfGame(arr,i+1,j-1));

    return dp[i][j] = max(res1,res2);
     
}

int main()
{
    int arr1[] = { 8, 15, 3, 7 }; 
    int n = sizeof(arr1) / sizeof(arr1[0]);
    memset(dp,-1,sizeof(dp)); 
    printf("%d\n", optimalStrategyOfGame(arr1, 0,n-1)); 
  
    int arr2[] = { 2, 2, 2, 2 }; 
    n = sizeof(arr2) / sizeof(arr2[0]);
    memset(dp,-1,sizeof(dp)); 
    printf("%d\n", optimalStrategyOfGame(arr2, 0,n-1)); 
  
    int arr3[] = { 20, 30, 2, 2, 2, 10 }; 
    n = sizeof(arr3) / sizeof(arr3[0]);
    memset(dp,-1,sizeof(dp)); 
    printf("%d\n", optimalStrategyOfGame(arr3, 0,n-1)); 
  
    return 0; 
}