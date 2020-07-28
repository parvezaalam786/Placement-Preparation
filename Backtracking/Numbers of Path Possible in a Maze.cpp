#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007
#define ff first
#define ss second

int visited[100][100]; // visited array is needed so that we do not visit the same cell twice
int totalpaths;
void go(vector<vector<int>> &arr, int sx, int sy, int dx, int dy, int r, int c)
{
	if (sx<0 or sy<0 or sx >= r or sy >= c or arr[sx][sy] == 0 or visited[sx][sy] == 1)
		return;
	if (sx == dx and sy == dy)
	{
		totalpaths++;
	}
	visited[sx][sy] = 1;

	//4 directions to move
	go(arr, sx, sy + 1, dx, dy, r, c);
	go(arr, sx, sy - 1, dx, dy, r, c);
	go(arr, sx + 1, sy, dx, dy, r, c);
	go(arr, sx - 1, sy, dx, dy, r, c);

	//Backtracking
	visited[sx][sy] = 0;
}
void solve()
{
	int r, c;
	cin >> r >> c;

	vector<vector<int>> arr(r, vector<int>(c));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cin >> arr[i][j];
	}
	totalpaths = 0;
	memset(visited, 0, sizeof(visited));
	go(arr, 0, 0, r - 1, c - 1, r, c);
	cout << totalpaths << "\n";
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
1 1 1 0
0 1 1 0
1 1 1 1
output:
4
*/