//https://www.hackerrank.com/challenges/pythagorean-triple/problem
#include<bits/stdc++.h>
using namespace std;
#define int long long

/*
For Pythgoras triplet h^2 = p^2 + b^2
m^2+n^2, 2mn, m^2-n^2 are satisfying the pythagoras triplet condition

	if(N==1 or N==2) then triplet does not exit

	if(N is even)
		2mn = N
	=>	mn = (N/2)*1
	=> m = (N/2) and n = 1

	if(N is odd)
		m^2 - n^2 = N
	=>	(m+n)*(m-n) = N*1
	=> 	(m+n) = N and (m-n) = 1
	=> 	m = (N+1)/2 and n = (N-1)/2
*/


void solve()
{
	int N;
	cin >> N;

	if (N % 2 == 0)
	{
		int m = (N / 2);
		int n = 1;
		cout << N << " " << m*m + n*n << " " << m*m - n*n;
	}
	else
	{
		int m = (N + 1) / 2;
		int n = (N - 1) / 2;
		cout << N << " " << m*m + n*n << " " << 2 * m*n;
	}

}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
