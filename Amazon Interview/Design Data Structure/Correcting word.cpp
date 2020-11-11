/*
You are tasked to develop a simple search engine that also takes care of correcting the
spelling mistakes and shows the words matching the given work in the dictionary.
(It is also given that user can make at most one spelling mistake)
Input: D = ["abc", "bcd", "ad", "ab"]
User:  1. "bbc"
       Return ["abc"]
*/
#include<bits/stdc++.h>
using namespace std;

struct trie
{
    map<char, trie*> m1;
    bool isend;
    trie()
    {
        isend = false;
    }
};

struct trie *root;
void insert(string word)
{
    struct trie *curr = root;
    for (auto ch : word)
    {
        if (curr->m1.count(ch) == 0)
            curr->m1[ch] = new trie();
        curr = curr->m1[ch];
    }
    curr->isend = true;
}
bool search(string str)
{
    struct trie *curr = root;
    for (char ch :  str)
    {
        if (!curr->m1[ch])
        {
            return false;
        }
        curr = curr->m1[ch];
    }
    return curr->isend;
}
void dfs(string word, int idx, vector<string>& ans, bool flag, trie *curr, string &temp)
{
    if (idx == word.length())
    {
        if (curr->isend == true)
            ans.push_back(temp);
        return;
    }
    for (auto i : curr->m1)
    {
        if (i.first == word[idx])
        {
            temp.push_back(i.first);
            dfs(word, idx + 1, ans, flag, i.second, temp);
            temp.pop_back();
        }
        else if (flag == true)
        {
            temp.push_back(i.first);
            dfs(word, idx + 1, ans, false, i.second, temp);
            temp.pop_back();
        }
    }
}

int main()
{
    root = new trie();
    vector<string> arr = {"abc", "bcd", "ad", "ab", "pufsy", "puscy", "passy"};
    for (int i = 0; i < arr.size(); i++)
    {
        insert(arr[i]);
    }
    string word = "pussy";
    vector<string> ans;
    string temp = "";
    dfs(word, 0, ans, true, root, temp);
    for (auto i : ans)
        cout << i << " ";

    // if (search("abc"))
    //     cout << "Yes";
    return 0;
}

