#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);
#define endl "\n"

int N;
int price[1010];
int profit[1010][1010];
int maxprofit(){
    int year = N;
    for(int i=0;i<N;i++){
        profit[i][i] = price[i]*year;
    }
    int a = 0;
    year--;
    for(int i=1;i<N;i++){
        a = i;
        for(int j=0;j<N-i;j++){
            profit[j][a] = max(price[j]*year+profit[j+1][a],price[a]*year+profit[j][a-1]);
            a++;
        }
        year--;
    }
    return profit[0][N-1];
}
int main()
{
    //freopen("Test.txt","r",stdin);
    fast_io;
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>price[i];
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            profit[i][j] = -1;
        }
    }
    int ans = maxprofit();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<profit[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}