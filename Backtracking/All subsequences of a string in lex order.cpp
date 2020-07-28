#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007
#define ff first
#define ss second

string ans = "";
multiset<string> subs;
void go(string& s1, int pos)
{
	subs.insert(ans);
	// cout << ans << "\n";
	for (int i = pos; i < s1.length(); i++)
	{
		ans.push_back(s1[i]); // considering the current character
		go(s1, i + 1);
		ans.pop_back(); // not considering
	}
}

void solve()
{
	int n; // no. of strings
	cin >> n;
	while (n--)
	{
		subs.clear();
		string s1;
		cin >> s1;
		go(s1, 0);
		for (auto i : subs)
			cout << i << "\n";
	}
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
