#include<bits/stdc++.h>
using namespace std;

int dp[10010];

void nthUgly()
{
    dp[0] = 0;
    dp[1] = 1;
    
    int num2 = 2,num3 = 3,num3 = 5;
    int i2 = 1,i3 = 1,i5 = 1;
    int num;
    for(int i=2;i<=10000;i++)
    {
        num = min(num2,min(num3,num5));
        dp[i] = num;
        if(num==num2)
        {
            i2+=1;
            num2 = dp[i2]*2;
        }
        if(num==num3)
        {
            i3+=1;
            num3 = dp[i3]*3;
        }
        if(num==num5)
        {
            i5+=1;
            num5 = dp[i5]*5;
        }
    }
}

int main()
{
    int T; cin>>T;
    memset(dp,0,sizeof(dp));
    while(T--)
    {
        int n; cin>>n;
        cout<<dp[n]<<"\n";
    }
    return 0;
}