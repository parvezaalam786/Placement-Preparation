#include<bits/stdc++.h>
using namespace std;
/*
The idea here is to pop all the characters whose frequency is greater than 0 and are greater than the
current character. The string that will remain at last will be our lexographically smallest string having
all the unique characters of the string.
*/


string removeDuplicateLetters(string s)
{
    if (s.length() <= 1)
        return s;
    map<char, int> cnt;
    map<char, bool> vis; // for removing the duplicates
    for (char ch = 'a'; ch <= 'z'; ch++)
        vis[ch] = false;
    for (auto &ch : s)
        cnt[ch]++;
    string res = "";   // the length of res will never go beyond cause of unique characters
    res += s[0];
    vis[s[0]] = true;
    cnt[s[0]]--;

    for (int i = 1; i < s.length(); i++)
    {
        cnt[s[i]]--;
        if (vis[s[i]])
            continue;
        while (res.size() > 0 and res.back() > s[i] and cnt[res.back()] > 0)
        {
            vis[res.back()] = false;
            res.pop_back();
        }
        res += s[i];

        vis[s[i]] = true;
    }
    return res;
}

int main()
{
    string s = "bcbcbcababa";
    cout << removeDuplicateLetters(s);
    return 0;
}