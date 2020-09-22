#include<bits/stdc++.h>
using namespace std;

/*
https://codeforces.com/contest/271/problem/D

The idea here is that we are creating all the unique substring and then checking if they validate the condition.
*/

string s, t;
int n, k, ans = 0;
int bad[26];

struct node
{
    struct node *child[26];
    bool isend = false;
};

struct node *root;
void insert(int start)
{
    struct node *curr = root;
    for (int i = start; i < n; i++)
    {
        int ch = s[i] - 'a';
        if (!curr->child[ch])
        {
            curr->child[ch] = new node();
        }
        curr = curr->child[ch];
        curr->isend = true;
    }
}

void search(struct node *curr, int cnt)
{
    for (int i = 0; i < 26; i++)
    {
        if (curr->child[i])
            search(curr->child[i], cnt + bad[i]);
    }
    if (curr->isend)  // checing for the validation
        ans += (cnt <= k);
}

int main()
{
    cin >> s >> t >> k;
    n = s.length();

    for (int i = 0; i < 26; i++)
        bad[i] = (t[i] == '0');

    root = new node();

    for (int i = 0; i < n; i++)
        insert(i);

    search(root, 0);
    cout << ans << "\n";

    return 0;
}