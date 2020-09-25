//Minimum weight hamiltonian path

#include<bits/stdc++.h>
using namespace std;
#define inf 99999

int n = 4;
int dist[10][10] = {
	{0, 20, 42, 25},
	{20, 0, 30, 34},
	{42, 30, 0, 10},
	{25, 34, 10, 0}
};
// If all cities have been visited then the mask will me all set to 1
// mask denotes the set of cities which have been visited

int visited_all = (1 << n) - 1;
int dp[100][100];

int tsp(int mask, int pos)
{
	if (mask == visited_all) // if all the cities have been visited then we return the
	{	// distance bw the curr city and the source
		return dist[pos][0];
	}

	if (dp[mask][pos] != -1)
		return dp[mask][pos];
	int ans = inf;
	// try to go to an unvisited city
	for (int city = 0; city < n; city++)
	{
		if ((mask & (1 << city)) == 0) // the current city is not visited
		{
			int temp = dist[pos][city] + tsp(mask | (1 << city), city);
			ans = min(ans, temp);
		}
	}
	return dp[mask][pos] = ans;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cout << tsp(1, 0) << "\n";
	return 0;
}



