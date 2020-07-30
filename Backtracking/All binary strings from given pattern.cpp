/*
Given a string containing of ‘0’, ‘1’ and ‘?’ wildcard characters,
generate all binary strings that can be formed by replacing each
wildcard character by ‘0’ or ‘1’.
*/

#include<bits/stdc++.h>
using namespace std;

bool check(string& str)
{
	for (char ch : str)
	{
		if (ch == '?')
			return false;
	}
	return true;
}

void go(string& str, int pos)
{
	if (check(str))
	{
		cout << str << "\n";
		return;
	}
	if (str[pos] == '1' or str[pos] == '0')
	{
		go(str, pos + 1);
	}
	else if (str[pos] == '?')
	{
		str[pos] = '0';
		go(str, pos + 1);
		str[pos] = '1';
		go(str, pos + 1);
		str[pos] = '?'; // backtracking
	}
}

void solve()
{
	string str;
	cin >> str;

	go(str, 0);
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
