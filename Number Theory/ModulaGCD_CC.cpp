#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define int long long
#define inf 1e9
#define mod 1000000007

int power(int a, int n, int d)
{
    int res = 1;
    while (n)
    {
        if (n & 1)
        {
            res = ((res % d) * (a % d)) % d;
            n--;
        }
        else
        {
            a = ((a % d) * (a % d)) % d;
            n /= 2;
        }
    }
    return res;
}

int GCD(int A, int B, int N)
{
    if (A == B)
    {
        return (power(A, N, mod) + power(B, N, mod)) % mod;
    }
    int candidate = 1;
    int num = A - B;
    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            int temp = (power(A, N, i) + power(B, N, i)) % i;
            if (temp == 0)
                candidate = max(candidate, i);
            temp = (power(A, N, num / i) + power(B, N, num / i)) % (num / i);
            if (temp == 0)
                candidate = max(candidate, num / i);
        }
    }
    return candidate % mod;
}

void solve()
{
    int A, B, N, T;
    cin >> T;
    while (T--)
    {
        cin >> A >> B >> N;
        cout << GCD(A, B, N) << "\n";
    }
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
