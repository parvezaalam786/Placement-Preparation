#include<bits/stdc++.h>
using namespace std;

//Complexity is O(2^n) without memoization
int memo[100][100] ;
int maxProfit1(int arr[],int beg,int end,int year){
    if(beg>end){
        return 0;
    }
    if(memo[beg][end]!=-1)
        return memo[beg][end];
    int q1 = arr[beg]*year+maxProfit1(arr,beg+1,end,year+1);
    int q2 = arr[end]*year+maxProfit1(arr,beg,end-1,year+1);
    int ans = max(q1,q2);
    memo[beg][end] = ans;
    return ans;
}
int maxProfit(int arr[],int n){
    int dp[100][100] = {};
    int year = n;
    for(int i=0;i<n;i++){
        dp[i][i] = year*arr[i];
    }
    --year;
    for(int len=2;len<=n;len++){
        int srt = 0;
        int end = n-len;
        while(srt<=end){
            int endWindow = srt+len-1;
            dp[srt][endWindow] = max(arr[srt]*year+dp[srt+1][endWindow],
                                    arr[endWindow]*year+dp[srt][endWindow-1]);
                                    srt++;
        }
        --year;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<setw(3)<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[0][n-1];
}

int main(){
    int arr[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(memo,-1,sizeof(memo));
    int ans = maxProfit(arr,n);
    cout<<ans<<endl;
    return 0;
}