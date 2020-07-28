#include<bits/stdc++.h>
using namespace std;
#define int long long

void go(vector<vector<int>>& arr, int x, int y, int r, int c, vector<vector<bool>>& vis)
{
	if (x<0 or x>r or y<0 or y>c or vis[x][y] == true)
		return;
	vis[x][y] = true;
	if (x == r and y == c)
	{
		for (int i = 0; i <= r; i++)
		{
			for (int j = 0; j <= c; j++)
			{
				if (vis[i][j])
					cout << arr[i][j] << " ";
			}
		}
		cout << "\n";
	}
	go(arr, x, y + 1, r, c, vis);//right
	go(arr, x + 1, y, r, c, vis);//down
	vis[x][y] = false;// for backtracking
}

void solve()
{
	int r, c;
	cin >> r >> c;

	vector<vector<int>> arr(r, vector<int>(c));
	vector<vector<bool>> vis(r, vector<bool>(c, false));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cin >> arr[i][j];
	}
	go(arr, 0, 0, r - 1, c - 1, vis);
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
/*
2
3
1 2 3
4 5 6

1 2 3 6
1 2 5 6
1 4 5 6


3 3
1 2 3
4 5 6
7 8 9

1 2 3 6 9
1 2 5 6 9
1 2 5 8 9
1 4 5 6 9
1 4 5 8 9
1 4 7 8 9
*/