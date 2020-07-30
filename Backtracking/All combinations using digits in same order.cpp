#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
/*
Given the input string of numbers, find all combinations that can be formed
using digits in the same order.
For 123:
	1 2 3
	1 23
	12 3
	123

We can see that at each step we have two choices:
a) Either space will come
b) Space will not come
*/
void go(string s1, string temp, int idx)
{
	if (idx == s1.length())
	{
		cout << temp << "\n";
		return;
	}

	go(s1, temp + " " + s1[idx], idx + 1); // taking the space

	go(s1, temp + s1[idx], idx + 1); // not taking the space
}
void solve()
{
	string num;
	cin >> num;
	string temp;
	temp.push_back(num[0]);
	go(num, temp, 1);

}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
