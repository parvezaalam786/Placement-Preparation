#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
int maxProfit(int price[],int n,int k)
{
    int profit[k+1][n+1];
    for(int i=0;i<=k;i++)
        profit[i][0] = 0;

    for(int i=0;i<=n;i++)
        profit[0][i] = 0;
    
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<n;j++)
        {
            int max_so_far = -inf;
            for(int m=0;m<j;m++)
            {
                max_so_far = max(max_so_far,price[j]-price[m]+profit[i-1][m]);
            } 
            profit[i][j] = max(profit[i][j-1],max_so_far);
        }
    }
    return profit[k][n-1];
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        int n,k;
        cin>>k>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int ans = maxProfit(arr,n,k);
        
        cout<<ans<<"\n";
    }
    return 0;
}