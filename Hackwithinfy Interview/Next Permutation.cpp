#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &arr)
{
    int n = arr.size();
    int k = -1;
    for (int i = n - 1; i >= 1; i--) // finding the first decreasing element
    {
        if (arr[i - 1] < arr[i])
        {
            k = i - 1;
            break;
        }
    }
    if (k == -1) // the array is in decreasing order
    {
        sort(arr.begin(), arr.end());
        return arr;
    }

    int mn = INT_MAX;

    int idx = n - 1;

    for (int i = n - 1; i > k; i--) // finding the element just greater than arr[k]
    {
        if (arr[i] > arr[k] and arr[i] < mn)
        {
            mn = arr[i];
            idx = i;
        }
    }
    swap(arr[k], arr[idx]);
    reverse(arr.begin() + k + 1, arr.end());
    return arr;
}


int main()
{
    vector<int> arr = {1, 5, 8, 4, 7, 6, 5, 3, 1};

    nextPermutation(arr);

    for (const auto &i : arr)
        cout << i << " ";

    return 0;
}