#include<bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/add-and-search-word-data-structure-design/
*/

class TrieNode
{
public:
	vector<TrieNode*> next;
	bool isend;
	TrieNode()
	{
		isend = false;
		next.resize(26, NULL);
	}
};

class WordDictionary
{
public:
	/*Initialize your data structure here*/
	TrieNode *root;
	WordDictionary()
	{
		root = new TrieNode();
	}

	/*Adding a word into the trie*/
	void addWord(string word)
	{
		TrieNode *curr = root;
		for (char ch : word)
		{
			if (!curr->next[ch - 'a'])
			{
				curr->next[ch - 'a'] = new TrieNode();
			}
			curr = curr->next[ch - 'a'];
		}
		curr->isend = true;
	}

	/*Returns if the word is in the trie. A . can represent any character*/
	bool search(string word)
	{
		return Find(word, root);
	}

	bool Find(string word, TrieNode *curr)
	{
		for (int i = 0; i < word.size(); i++)
		{
			char ch = word[i];
			if (ch != '.')
			{
				if (!curr->next[ch - 'a'])
					return false;
				curr = curr->next[ch - 'a'];
			}
			else
			{
				/*here we have to replace the '.' with the current character */
				for (int j = 0; j < 26; j++)
				{
					if (curr->next[j] and Find(word.substr(i + 1), curr->next[j]))
					{
						return true;
					}
				}
				return false;
			}
		}
		return curr->isend;
	}
};


void solve()
{
	WordDictionary *Trie1 = new WordDictionary();
	Trie1->addWord("abc");
	Trie1->addWord("bcdef");
	Trie1->addWord("xyzabc");

	if (Trie1->search("xyz.bc"))
		cout << "Word found";
	else
		cout << "Not found";

	if (Trie1->search("abc"))
		cout << "Word found";
	else
		cout << "Not found";

	if (Trie1->search("xyz"))
		cout << "Word found";
	else
		cout << "Not found";
}


signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
