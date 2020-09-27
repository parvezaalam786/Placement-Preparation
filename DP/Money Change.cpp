///coins changing problem:
/*
Given a big amount N and the array of denominations S. 
Assuming infinite supply of each of S = {S1,S2�.Sm} denominations, 
find the number of ways to make change for N cents.
*/

///https://www.youtube.com/watch?v=_fgjrs570YE

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int dp[505][1000010];

int waysOfMakingChange(int coins[],int n,int amt,int dp[][1000010])
{
   for(int i=0;i<=n;i++)
      dp[i][0] = 1;
   
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=amt;j++)
      {
         if(j>=coins[i-1])
         {
            dp[i][j] = (dp[i-1][j]+dp[i][j-coins[i-1]])%mod;
         }
         else
            dp[i][j] = dp[i-1][j]%mod;
      }
   }
   return dp[n][amt];
}

int main()
{
   int T;
   cin>>T;
   while(T--)
   {
      int M; cin>>M;
      int amt;
      cin>>amt;
      int coins[M];
      for(int i=0;i<M;i++)
         cin>>coins[i];
      
      
      for(int i=0;i<M+1;i++)
         for(int j=0;j<amt+1;j++)
            dp[i][j] = 0;
      
      int ans = waysOfMakingChange(coins,M,amt,dp);
      cout<<ans<<"\n";
   }
   
}