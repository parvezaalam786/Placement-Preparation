/*
Success is Never Owned, It’s Rented, and the Rent is Due EveryDay!!
Love the music of silence.
*/
/*
Given a number K and string S of digits denoting a positive integer, build the largest number possible by performing swap operations on
the digits of S atmost K times.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test
case contains a positive integer K. The second line of each test case contains a string of digits denoting a positive integer.

Output:
Print out the largest number possible.

Constraints:
1 <= T <= 100
0 <   S <= 30
0 <   K  <= 10

Examples :
Input:
3
4
1234567
3
3435335
2
1034

Output:
7654321
5543333
4301

Explanation:
Testcase 1: Three swaps can make the input 1234567 to 7654321, swapping 1 with 7, 2 with 6 and finally 3 with 5.
*/
#include<bits/stdc++.h>
using namespace std;

void findMaximum(string str, int k, string &max_num)
{
    if (k == 0)
        return;
    int n = str.length();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (str[i] < str[j])
            {
                swap(str[i], str[j]);
                if (str.compare(max_num) > 0)
                    max_num = str;
                findMaximum(str, k - 1, max_num);
                swap(str[i], str[j]);
            }
        }
    }

}

void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        string str, max_num;
        int k;
        cin >> k >> str;
        max_num = str;
        findMaximum(str, k, max_num);
        cout << max_num << "\n";
    }

}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
