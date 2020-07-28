#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007
#define ff first
#define ss second

const int n = 8;
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool valid(int x, int y, int mat[n][n])
{
	return (x >= 0 and x<n and y >= 0 and y < n and mat[x][y] == -1);
}

bool go(int mat[n][n], int x, int y, int mv)
{
	if (mv == n * n)
	{
		return true;
	}
	for (int i = 0; i < 8; i++)
	{
		int x1 = x + dx[i];
		int y1 = y + dy[i];
		if (valid(x1, y1, mat))
		{
			mat[x1][y1] = mv;
			if (go(mat, x1, y1, mv + 1))
			{
				return true;
			}
			mat[x1][y1] = -1;
		}
	}
	return false;
}

void solve()
{
	int mat[n][n];
	memset(mat, -1, sizeof(mat));

	mat[0][0] = 0;

	if (go(mat, 0, 0, 1))
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << mat[i][j] << "\t";
			}
			cout << "\n";
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}

/*
0	59	38	33	30	17	8	63
37	34	31	60	9	62	29	16
58	1	36	39	32	27	18	7
35	48	41	26	61	10	15	28
42	57	2	49	40	23	6	19
47	50	45	54	25	20	11	14
56	43	52	3	22	13	24	5
51	46	55	44	53	4	21	12
*/