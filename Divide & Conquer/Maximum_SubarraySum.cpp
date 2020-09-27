#include <bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
    return (a>b)?a:b;
}
int max(int a, int b, int c)
{
    return max(max(a, b), c);
}
int maxCrossingSum(int arr[], int l, int m, int h)
{
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m + 1; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }
    return left_sum + right_sum;
}
int maxSubArraySum(int arr[], int l, int h)
{
    if (l == h)
    {
        return arr[l];
    }
    int m = (l + h) / 2;

    return max(maxSubArraySum(arr, l, m), maxSubArraySum(arr, m + 1, h), maxCrossingSum(arr, l, m, h));
}

int main()
{
    int T, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        int ans = maxSubArraySum(arr, 0, N - 1);
        cout << ans << endl;
    }
    return 0;
}