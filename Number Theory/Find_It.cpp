#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
vector<int> dp(1000000, 0);
int main()
{
    int long long n, q, val, k;
    cin >> n;
    while (n--)
    {
        cin >> val;
        for (int long long i = 1; i * i <= val; i++)
        {
            if (val % i == 0)
            {
                dp[i]++;
                if (i * i != val)
                    dp[val / i]++;
            }
        }
    }
    cin >> q;
    while (q--)
    {
        cin >> k;
        cout << dp[k] << endl;
    }
    return 0;
}
