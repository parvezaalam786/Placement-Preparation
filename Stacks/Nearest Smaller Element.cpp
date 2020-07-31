#include<bits/stdc++.h>
using namespace std;
/*
https://www.interviewbit.com/problems/nearest-smaller-element/
*/
vector<int> prevSmaller(vector<int>& arr)
{
	int n = arr.size();
	stack<int> left;
	left.push(-1);
	vector<int> nextSmaller(n);
	for (int i = 0; i < n; i++)
	{
		if (left.top() < arr[i])
			nextSmaller[i] = left.top();
		else
		{
			while (left.top() >= arr[i])
				left.pop();
			nextSmaller[i] = left.top();
		}
		left.push(arr[i]);
	}
	return nextSmaller;
}


void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<int> ans = prevSmaller(arr);
	for (auto i : ans)
		cout << i << " ";
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
