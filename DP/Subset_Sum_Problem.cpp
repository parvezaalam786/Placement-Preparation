#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL);
#define input freopen("Test.txt","r",stdin)
#define output freopen("Output.txt","w",stdout);
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define F(i,a,b) for(int i = a; i <= b; i++)
#define pb push_back
#define eb emplace_back
#define inf 1000000000
const double pi = 3.141592653589793238460;
#define debug false
#define mod 1000000007

bool subsetSum1(int arr[], int n, int sum)
{
    bool dp[sum + 1] = {0};
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        int curr_ele = arr[i];
        for (int j = sum; j >= curr_ele; j--)
        {
            if (dp[j] || (dp[j - curr_ele] == 0))
                continue;
            else
                dp[j] = 1;
        }
    }

    return dp[sum];

}

bool subsetSum(int arr[], int n, int sum) // spacw   O(M*N)
{
    bool dp[n + 1][sum + 1];
    F(i, 0, n)
    {
        dp[i][0] = true;
    }
    F(i, 0, n)
    {
        dp[0][i] = false;
    }
    F(i, 1, n)
    {
        F(j, 1, sum)
        {
            if (j < arr[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            if (j >= arr[i - 1])
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }

        }
    }
    return dp[n][sum];
}

void solve()
{
    int n, sum;
    cin >> n >> sum;
    int arr[n];
    for (int &i : arr)
        cin >> i;
    if (subsetSum1(arr, n, sum))
        cout << "Yes" << "\n";
    else cout << "No" << "\n";

}

int main()
{
    // fast_io; // input; // output; // if(debug){watch_is();}
    solve();
    return 0;
}