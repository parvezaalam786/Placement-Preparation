#include<bits/stdc++.h>
using namespace std;
#define ll          long long int
#define endl        "\n"
#define fast_io     ios::sync_with_stdio(false);cin.tie(NULL);
#define input       freopen("Test.txt","r",stdin)
#define output      freopen("Output.txt","w",stdout);
#define what_is(x)  cout<<#x<<" is "<<x<<endl;
#define pb          push_back
#define eb          emplace_back
#define inf         1000000000
const double pi = 3.141592653589793238460;
#define mod 1000000007
int dp[10005][10005];

int maxSum(int arr[],int n,int i,int j)
{
     if(i>=n)
          return 0;
     if(j<0)
          return 0;
     if(dp[i][j]!=-1)
          return dp[i][j];
     if(i>j)
          return 0;
     if(i==j)
          return dp[i][j] = arr[i];
     if(i+1==j)
          return dp[i][j] = max(arr[i],arr[j]);
     
     
     
     int &ans = dp[i][j];
     
     ans = max(arr[i]+min(maxSum(arr,n,i+2,j),maxSum(arr,n,i+1,j-1)) ,
               arr[j]+min(maxSum(arr,n,i+1,j-1),maxSum(arr,n,i,j-2)));
     
     return ans;     
}

int main()
{
     fast_io;
     ///input;
     ///output;
    
     int N;
     cin>>N;
     int arr[N];
     for(int i=0;i<N;i++)
          cin>>arr[i];
     for(int i=0;i<N+1;i++)
          for(int j=0;j<N+1;j++)
               dp[i][j] = -1;
     
     maxSum(arr,N,0,N-1);
     /*for(int i=0;i<N;i++)
     {
          for(int j=0;j<N;j++)
               cout<<dp[i][j]<<"  ";
          cout<<endl;
     }*/
     cout<<(dp[0][N-1])<<endl;
     return 0;
}