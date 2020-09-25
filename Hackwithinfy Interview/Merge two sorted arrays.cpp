#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr1, vector<int>& arr2)
{
    int n = arr1.size();
    int m = arr2.size();

    arr1.resize(m + n, 0);

    int p1 = n - 1;
    int p2 = m - 1;
    for (int i = n + m - 1; i >= 0; i--)
    {
        if (p2 < 0)
            break;
        if (p1 >= 0 and arr1[p1] > arr2[p2])
        {
            arr1[i] = arr1[p1];
            p1--;
        }
        else
        {
            arr1[i] = arr2[p2];
            p2--;
        }
    }
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 3, 4, 5, 6, 7};
    vector<int> arr2 = {1, 2, 3, 4, 5};

    merge(arr1, arr2);
    for (auto &i : arr1)
        cout << i << ' ';
}