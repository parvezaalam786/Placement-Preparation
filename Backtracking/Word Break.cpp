#include<bits/stdc++.h>
using namespace std;
#define int long long

unordered_set<string> s;

void go(string str, int len, string res)
{
	for (int i = 1; i <= len; i++)
	{
		string pre = str.substr(0, i);
		if (s.find(pre) != s.end())
		{
			if (i == len)
			{
				res += pre;
				cout << res << "\n";
			}
			go(str.substr(i, len - i), len - i, res + pre + " ");
		}
	}
}
void solve()
{
	s.insert("i");
	s.insert("love");
	s.insert("sam");
	s.insert("sung");
	s.insert("samsung");
	string str;
	cin >> str;

	go(str, str.length(), "");

}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
/*
ilovesamsung

i love sam sung
i love samsung
*/