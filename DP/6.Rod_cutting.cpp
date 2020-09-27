#include<bits/stdc++.h>
using namespace std;
int memo[100];

//Top down approach     
int maxProfit(int arr[],int totalLen){
    if(totalLen == 0) return 0;
    if(memo[totalLen] != -1){
        return memo[totalLen];
    }
    int best = 0;
    for(int i=1;i<=totalLen;i++){
        int netProfit = arr[i]+maxProfit(arr,totalLen - i);
        best = max(best,netProfit);
    }
    memo[totalLen] = best;
    return best;
}
//Bottom up appproach 
int maxProfit1(int arr[],int totalLen){
    int dp[100] = {};
    for(int i=1;i<=totalLen;i++){
        int best = 0;
        for(int cut = 1;cut<=i;cut++){
            best =max(best,arr[cut] + dp[i-cut]);
        }
        dp[i] = best;
    }
    return dp[totalLen];
}

int main()
{
    int priceOfEachLen[100];
    int totalLen;
    cin>>totalLen;

    for(int i=1;i<=totalLen;i++){
        cin>>priceOfEachLen[i];
    }

    memset(memo,-1,sizeof(memo));
    int ans1 = maxProfit(priceOfEachLen,totalLen);
    int ans2 = maxProfit1(priceOfEachLen,totalLen);
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}