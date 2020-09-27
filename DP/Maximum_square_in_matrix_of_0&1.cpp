#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010];

int maxSquareMat(int arr[][1010],int r,int c)
{
    int maxSize = 0;
    for(int i=0;i<r;i++)
    {
        dp[i][0] = arr[i][0];
        if(dp[i][0]==1)
            maxSize = 1;
    }
    for(int i=0;i<c;i++)
    {
        dp[0][i] = arr[0][i];
        if(dp[0][i]==1)
            maxSize = 1;
    }
    for(int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)
        {
            if(arr[i][j] == 0)
                continue;
            int t = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
            dp[i][j] = t+1;
            if(dp[i][j]>maxSize)
                maxSize = dp[i][j];
        }
    }
    return maxSize;
}

int main()
{
    int r,c;
    cin>>r>>c;
    int arr[1010][1010];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>arr[i][j];
        }
    }

    int ans = maxSquareMat(arr,r,c);
    cout<<ans<<"\n";
    return 0;
}