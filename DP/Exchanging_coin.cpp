/*
EXCHANGING COINS
Tughlaq introduces a strange monetary system. He introduces copper coins and each coin has a number written on it.
 A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4. A coin can also be sold for gold. 
 One can get as much grams of gold as the number written on the coin. 
You have one copper coin. What is the maximum weight of gold one can get from it?


*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll coin_exchange(ll n,ll dp[])
{
	if(n<=11)
	{
		dp[n] = n;
		return dp[n];
	}
	if(dp[n]!=0)
		return dp[n];
	
	ll ans = max(n,coin_exchange(n/2,dp)+coin_exchange(n/3,dp)+coin_exchange(n/4,dp));
	return dp[n] = ans;
}

int main()
{
	ll n;
	cin>>n;
	ll dp[n+1];
	for(int i=0;i<=n;i++)
		dp[i] = 0;
	ll ans = coin_exchange(n,dp);
	cout<<ans<<"\n";
	return 0;
}