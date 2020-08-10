/*
Chase excellence, rating will come automatically.
*/
/*
https://www.interviewbit.com/problems/next-permutation/
*/

/*
The idea here is:
i) Base case:  if the array is already sorted in decreasing order then there is no next permutation
ii) Move from right end and check for the longest decreasing order like in 1 2 3 6 5 4 it is 6 5 4.... and find the index at which it break, here k = 2(0 based index)
iii)Now again move from right and check for the element which is smallest but greater arr[k]
iv) swap(arr[k],arr[largest]) and reverse the array from index k+1 to n(basically sorting in this part)
eg:
6
5 6 1 2 4 3
op:
5 6 1 3 2 4


*/

#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &arr)
{
    int n = arr.size();

    int k = -1;
    for (int i = n - 1; i >= 1; i--)
    {
        if (arr[i - 1] < arr[i])
        {
            k = i - 1;
            break;
        }
    }
    if (k == -1)
    {
        sort(arr.begin(), arr.end());
        return arr;
    }
    // cout << k << "\n";
    int mn = INT_MAX;
    int idx = n - 1;
    for (int i = n - 1; i > k; i--)
    {
        if (arr[i] > arr[k] and arr[i] < mn)
        {
            mn = arr[i];
            idx = i;
        }
    }
    // cout << idx << "\n";
    swap(arr[k], arr[idx]);
    reverse(arr.begin() + k + 1 , arr.end());
    return arr;

}


void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    nextPermutation(arr);
    for (auto i : arr)
        cout << i << ' ';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
