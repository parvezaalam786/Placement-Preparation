#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007
#define ff first
#define ss second

struct trie
{
	unordered_map<char, struct trie*> m1;
	bool isend;
	trie()
	{
		isend = false;
	}
};
struct trie *root;
bool consistent;

void insert(string str)
{
	struct trie *curr = root;
	for (char ch : str)
	{
		// checking if any string is prefix of current string
		if (curr->isend == true)
			consistent = false;
		if (!curr->m1.count(ch))
		{
			curr->m1[ch] = new trie;
		}
		curr = curr->m1[ch];
	}
	curr->isend = true;

	//checking if there is any string of which the current string is prefix
	for (int i = 0; i < 10; i++)
	{
		if (curr->m1.count(i + '0'))
			consistent = false;
	}
}

void solve()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		root = new trie;
		consistent = true;
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			insert(str);
		}
		if (consistent)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
