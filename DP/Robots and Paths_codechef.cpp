// https://www.codechef.com/problems/CD1IT4
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int dp[1010][1010];
int Ways(int M,int N){
    if(dp[0][0]==-1)
        return 0;
    for(int i=0;i<N;i++){
        if(dp[0][i]==-1)
            break;
        dp[0][i] = 1;    
    }
    for(int i=0;i<M;i++){
        if(dp[i][0]==-1)
            break;
        dp[i][0] = 1;    
    }    
    for(int i=1;i<M;i++){
        for(int j=1;j<N;j++){
            if(dp[i][j]==-1){
                continue;
            }
            dp[i][j] = 0;
            if(dp[i][j-1]!=-1){
                dp[i][j] = dp[i][j-1]%mod;
            }
            if(dp[i-1][j]!=-1){
                dp[i][j] = (dp[i][j]+dp[i-1][j])%mod;
            }
        }
    }
    if(dp[M-1][N-1]==-1)
        return 0;
    return dp[M-1][N-1];    
}
int main()
{
    memset(dp,0,sizeof(dp));
    int M,N,P;
    cin>>M>>N>>P;
    for(int i=0;i<P;i++){
        int x,y;
        cin>>x>>y;
        dp[x-1][y-1] = -1;
    }
    cout<<Ways(M,N)<<endl;
    return 0;
}