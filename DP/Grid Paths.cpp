#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
	int n;
	cin >> n;
	char mat[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
		}
	}
	int ans[n][n];
	memset(ans, 0, sizeof(ans));
	bool check = false;
	for (int i = 0; i < n; i++)
	{
		if (mat[i][0] == '*')
		{
			ans[i][0] = -1;
			check = true;
		}
		else if (check == false)
			ans[i][0] = 1;
		else ans[i][0] = 0;
	}
	check = false;
	for (int i = 0; i < n; i++)
	{
		if (mat[0][i] == '*')
		{
			ans[0][i] = -1;
			check = true;
		}
		else if (check == false)
			ans[0][i] = 1;
		else ans[0][i] = 0;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (mat[i][j] == '*')
			{
				ans[i][j] = -1;
				continue;
			}
			int x = 0, y = 0;
			if (ans[i - 1][j] >= 0)
				x = ans[i - 1][j];
			if (ans[i][j - 1] >= 0)
				y = ans[i][j - 1];
			ans[i][j] = x + y;
			if (ans[i][j] >= mod)
				ans[i][j] -= mod;
		}
	}
	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<n;j++)
	// 		cout<<ans[i][j]<<" ";
	// 	cout<<"\n";
	// }
	if (ans[n - 1][n - 1] == -1)
		ans[n - 1][n - 1] = 0;
	cout << ans[n - 1][n - 1] << "\n";
	return 0;
}