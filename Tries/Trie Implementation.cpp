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
	struct trie *child[26];
	bool isend;
	trie()
	{
		memset(child, 0, sizeof(child));
		isend = false;
	}
};
struct trie *root;

void insert(string str)
{
	struct trie *curr = root;
	for (char ch : str)
	{
		int idx = ch - 'a';
		if (curr->child[idx] == NULL)
		{
			curr->child[idx] = new trie;
		}
		curr = curr->child[idx];
	}
	curr->isend = true;
}

bool search(string str)
{
	struct trie *curr = root;
	for (char ch :  str)
	{
		int idx = ch - 'a';
		if (curr->child[idx] == NULL)
			return false;
		curr = curr->child[idx];
	}
	return curr->isend;
}

void solve()
{
	int n;
	cin >> n;
	root = new trie;
	while (n--)
	{
		string str;
		cin >> str;
		insert(str);
	}
	int q;
	cin >> q;
	while (q--)
	{
		string str;
		cin >> str;
		if (search(str))
		{
			cout << str << " is present" << "\n";
		}
		else
		{
			cout << str << " is not present" << "\n";
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
