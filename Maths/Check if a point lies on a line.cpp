#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define ff first
#define ss second

int fun(pair<float, float> p1, pair<float, float> p2, pair<float, float> q)
{
	float x1, y1, x2, y2, x3, y3;
	x1 = p1.ff;
	y1 = p1.ss;
	x2 = p2.ff;
	y2 = p2.ss;
	x3 = q.ff;
	y3 = q.ss;

	float slope1 = (y2 - y1) / (x2 - x1);
	float slope2 = (y3 - y2) / (x3 - x2);

	if (slope1 == slope2)
		return 0;
	else if (slope1 > slope2)
		return 1;
	else
		return 2;
}

void solve()
{
	pair<float, float> p1, p2, q;
	cin >> p1.ff >> p1.ss >> p2.ff >> p2.ss >> q.ff >> q.ss;

	int val = fun(p1, p2, q);
	if (val == 0)
		cout << "Collinear" << "\n";
	else if (val == 1)
		cout << "Clockwise" << "\n";
	else
		cout << "Anti Clockwise" << "\n";
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
