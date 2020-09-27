// Given n friends, each one can remain single or
// can be paired up with some other friend. 
// Each friend can be paired only once. 
// Find out the total number of ways in which friends can remain single or can be paired up.

// f(n) = f(n - 1) + (n - 1) * f(n - 2)  recurrence formed:   either the friend can remain single(f(n-1)) or he can pair with C(n-1,1)*f(n-2)


#include<bits/stdc++.h>
using namespace std;

int countFriendsPairings(int n)
{
    int dp[n+1];
    for(int i=0;i<=n;i++)
    {
        if(i<=2)
            dp[i] = i;
        else dp[i] = dp[i-1]+(i-1)*dp[i-2];
    }
    return dp[n];
}
int main()
{
    int n;
    // cin>>n;
    n = 4;
    cout<<countFriendsPairings(n)<<"\n";
    return 0;
}