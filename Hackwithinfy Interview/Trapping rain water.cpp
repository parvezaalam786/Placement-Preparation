#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& trap)
{
    int n = trap.size();
    if (n == 0)
        return 0;
    int maxL[n], maxR[n];
    maxL[0] = trap[0];

    for (int i = 1; i < n; i++)
    {
        maxL[i] = max(maxL[i - 1], trap[i]);
    }

    maxR[n - 1] = trap[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        maxR[i] = max(maxR[i + 1], trap[i]);
    }

    int water = 0;
    for (int i = 0; i < n; i++)
    {
        water += min(maxL[i], maxR[i]) - trap[i];
    }
    return water;
}
int main()
{
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << trap(arr);
    return 0;
}