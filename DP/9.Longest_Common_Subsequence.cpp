#include<bits/stdc++.h>
using namespace std;
int lcs(char X[],char Y[]){
    int m = strlen(X);
    int n = strlen(Y);
    int dp[100][100];

    //base cases filling for empty strings
    for(int i=0;i<=m;i++) dp[i][0] = 0;
    for(int j=0;j<=n;j++) dp[0][j] = 0;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int q = 0;
            if(X[i-1]==Y[j-1]){
                q = 1+dp[i-1][j-1];
            }
            else{
                q = max(dp[i-1][j],dp[i][j-1]);
            }
            dp[i][j] = q;
        }
    }

    //Printing the common subsequence
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    int a = 0;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(dp[i][j]>a){
                cout<<Y[j-1];
                a = dp[i][j];
            }             
        }
    }
    cout<<endl;
    return dp[m][n];
}
int main()
{
    char str1[100],str2[100];
    cin>>str1>>str2;
    int x = lcs(str1,str2);
    cout<<x<<endl;
    return 0;
}

/*
GXTXTAB
AGGTAB
0 0 0 0 0 0
0 0 1 1 1 1
0 0 1 1 1 1
0 0 1 1 2 2
0 0 1 1 2 2
0 0 1 1 2 2
0 1 1 1 2 3
0 1 1 1 2 3
4
*/