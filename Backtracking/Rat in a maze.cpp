/*check if the rat can reach the destination from the starting vertex.*/

#include<bits/stdc++.h>
using namespace std;

bool visited[100][100]; // visited array is needed so that we do not visit the same cell twice

bool go(vector<vector<int>> &arr, int sx, int sy, int dx, int dy, int r, int c)
{
	if (sx<0 or sy<0 or sx >= r or sy >= c or arr[sx][sy] == 0 or visited[sx][sy] == true)
		return false;
	visited[sx][sy] = true;
	if (sx == dx and sy == dy)
		return true;
	//backtracking
	// we can move in four directions
	if (go(arr, sx, sy + 1, dx, dy, r, c))
		return true;
	if (go(arr, sx, sy - 1, dx, dy, r, c))
		return true;
	if (go(arr, sx + 1, sy, dx, dy, r, c))
		return true;
	if (go(arr, sx - 1, sy, dx, dy, r, c))
		return true;

	return false;
}
void solve()
{
	int r, c;
	cin >> r >> c;

	vector<vector<int>> arr(r, vector<int>(c));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> arr[i][j];

	memset(visited, false, sizeof(visited));
	cout << go(arr, 0, 0, r - 1, c - 1, r, c) << "\n";
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}

/*
input:
4 4
1 0 0 0
1 1 0 1
0 1 0 0
1 1 1 1
output:
1
*/
