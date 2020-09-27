#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define int long long
#define inf 1e9
#define P 1000000007
int F[1000001];

int power(int a, int n)
{
	int res = 1;
	while (n)
	{
		if (n % 2)
			res = (res * 1LL * a) % P;
		n /= 2;
		a = (a * 1LL * a) % P;
	}
	return res;
}

int C(int n, int k)
{
	if (k > n) return 0;
	int res = F[n];

	//Since it is modulo P ..we can not divide it directly so we will multiply by its inverse modulo P calculated by Fermat's Litte Theorem
	res = (res * 1LL * power(F[k], P - 2)) % P;
	res = (res * 1LL * power(F[n - k], P - 2)) % P;
	return res;
}

void solve()
{
	F[0] = F[1] = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		F[i] = (F[i - 1] * 1LL * i) % P;
	}
	int q, n, k;
	cin >> q;
	while (q--)
	{
		cin >> n >> k;
		cout << C(n, k) << "\n";
	}

}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
