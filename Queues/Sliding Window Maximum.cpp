#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/sliding-window-maximum/
*/

/*
We can solve it by using deque.
The front of the deque always contains the maximum element in the window.
Steps:
1) if an element comes which is greater than the front of deque then we will pop elements till we found front of deque strictly
	greater than current element
	The idea behind this: the current element will always be present in the subsequent windows so there is no need of elements which
	comes before current element.
2) if an element comes which is smaller than deque front then we will push it to the deque cause it might be the greater element of
	next window, but before inserting it we will pop all those elements from the deque which are smaller than it.
	We will pop the elements which are smaller than current from the back of the deque.

But before performing the above steps we need to check if the deque still contains elements which are no longer part of our window,
if it has then we will pop it.
*/


vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	int n = nums.size();
	if (n == 0)
		return {};
	vector<int> res;
	deque<pair<int, int>> que;
	que.push_back({nums[0], 0});
	for (int i = 1; i < k; i++)
	{
		while (que.size() > 0 and que.front().second <= (i - k))
			que.pop_front();

		while (que.size() > 0 and que.back().first <= nums[i])
			que.pop_back();

		if (nums[i] <= que.front().first)
			que.push_back({nums[i], i});
		else
		{
			while (que.size() > 0 and nums[i] >= que.front().first)
				que.pop_front();
			que.push_back({nums[i], i});
		}
	}
	res.push_back(que.front().first);
	for (int i = k; i < n; i++)
	{
		while (que.size() > 0 and que.front().second <= (i - k)) // checking if deque still has elements which are not part of current window
			que.pop_front();

		while (que.size() > 0 and que.back().first <= nums[i]) // removing elements which are smaller than current
			que.pop_back();

		if (nums[i] <= que.front().first)
			que.push_back({nums[i], i});
		else
		{
			while (que.size() > 0 and nums[i] >= que.front().first) // removing from front which are smaller than current element
				que.pop_front();
			que.push_back({nums[i], i});
		}
		res.push_back(que.front().first);
	}
	return res;
}

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	vector<int> res = maxSlidingWindow(nums, k);
	for (auto x : res)
		cout << x << " ";
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
