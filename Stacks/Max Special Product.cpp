#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
/*
You are given an array A containing N integers. The special product of each ith integer in this array is defined as the product of the following:

LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (i>j). If multiple A[j]'s are present in multiple positions, the LeftSpecialValue is the maximum value of j.
RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (j>i). If multiple A[j]'s are present in multiple positions, the RightSpecialValue is the minimum value of j.
Write a program to find the maximum special product of any integer in the array.

NOTE: As the answer can be large, output your answer modulo 1^9 + 7.



Problem Constraints
1 <= N <= 105
1 <= A[i] <= 109

Sample input output:
4
1 4 3 4
3

3
10 7 100
0

11
5 9 6 8 6 4 6 9 5 4 9
80


*/

int maxSpecialProduct(vector<int>& arr)
{
	int n = arr.size();
	int left[n], right[n];
	stack<pair<int, int>> s1, s2;
	s1.push({0, 0});
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < s1.top().first)
			left[i] = s1.top().second;
		else
		{
			while (s1.size() > 1 and arr[i] >= s1.top().first)
				s1.pop();
			left[i] = s1.top().second;
		}
		s1.push({arr[i], i});
	}

	s2.push({0, 0});
	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] < s2.top().first)
			right[i] = s2.top().second;
		else
		{
			while (s2.size() > 1 and arr[i] >= s2.top().first)
				s2.pop();
			right[i] = s2.top().second;
		}
		s2.push({arr[i], i});
	}
	long long maxprod = 0;
	for (int i = 0; i < n; i++)
		maxprod = max(maxprod, left[i] * right[i] * 1LL);

	return maxprod % mod;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int ans = maxSpecialProduct(arr);
	cout << ans << "\n";
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
