#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<string>& words)
{
    int n = words.size();
    int dp[n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < words[i].length(); j++)
        {
            int ch = (words[i][j] - 'a');
            // cout << words[i][j] << ":" << ch << ",";
            dp[i] |= (1 << ch);
        }
        // cout << "\n";
    }
    // for (int i = 0; i < n; i++)
    //     cout << dp[i] << "\n";
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int nd = dp[i] & dp[j];
            if (nd == 0)
            {
                // cout << i << " " << j << "\n";
                int x = words[i].length() * words[j].length();
                ans = max(ans, x);
            }
        }
    }
    return ans;
}

int main()
{
    vector<string> arr = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    cout << maxProduct(arr);

    return 0;
}