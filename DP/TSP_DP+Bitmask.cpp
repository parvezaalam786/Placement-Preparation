#include<bits/stdc++.h>
using namespace std;


int n=4;
int dp[20][5]; //1<<n and n
int dist[10][10] = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
};
int VISITED_ALL = (1<<n) -1;

///Mask denotes the set of cities visited so far

int tsp(int mask,int pos){
    if(mask==VISITED_ALL){
        return dist[pos][0];
    }
    if(dp[mask][pos]!=-1)
        return dp[mask][pos];

    ///Try to go to every other city
    ///Reachable from the current city
    int ans = INT_MAX;
    for(int nextCity=0;nextCity<n;nextCity++){
        if((mask&(1<<nextCity))==0){
                ans = min(ans,dist[pos][nextCity] +
                          tsp((mask|(1<<nextCity)),nextCity));
           }
    }
    return dp[mask][pos] = ans;
}

int main(){

    memset(dp,-1,sizeof(dp));
    cout<<tsp(1,0)<<endl;


return 0;
}
