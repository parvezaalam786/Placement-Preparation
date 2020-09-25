#include<bits/stdc++.h>
using namespace std;

// the idea here is to swap every character with every other character

void permute(string s, int l, int r)
{
    if (l == r)
        cout << s << ",";
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(s[l], s[i]);
            permute(s, l + 1, r);
            swap(s[l], s[i]);
        }
    }
}

int main()
{
    string s = "abc";
    permute(s, 0, 2);
    return 0;
}