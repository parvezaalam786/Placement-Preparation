#include<bits/stdc++.h>
using namespace std;
/*
Find the number of substrings with equal first and last character.
string = "abca"
a b c a abca => 5

Approach:
we can match the following cases:
i+1,j --(a)
i,j-1 --(b)
i+1,j-1 --(c)

we know that:
 A union B = A + B - (A intersection B)

Therefore our answer = (a+b-c)
*/

int go(string str, int i, int j, int n)
{
	if (n == 1)
		return 1;
	if (n <= 0)
		return 0;

	int a = go(str, i + 1, j, n - 1);
	int b = go(str, i, j - 1, n - 1);
	int c = go(str, i + 1, j - 1, n - 2);

	int res = (a + b - c);
	if (str[i] == str[j])
		res++;
	return res;
}
void solve()
{
	string str;
	cin >> str;
	cout << go(str, 0, str.length() - 1, str.length());
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
