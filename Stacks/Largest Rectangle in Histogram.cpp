#include<bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/largest-rectangle-in-histogram/
*/
/*
If we clearly visualize the problem, then we will find that we are actually finding the indices of the nearest smaller to left
and indices of the nearest smaller to right cause that is the index after which we can not extend out maximum area.
area = (NSR[i]-NSL[i]-1)*height[i]
*/

/*
Nearest Smaller to left : if it does not exist we will put -1 there
*/
vector<int> NSL(vector<int>& heights)
{
	int n = heights.size();
	vector<int> left(n, 0);
	stack<pair<int, int>> stk;
	stk.push({ -1, -1 });
	for (int i = 0; i < n; i++)
	{
		if (heights[i] > stk.top().first)
		{
			left[i] = stk.top().second;
		}
		else
		{
			while (heights[i] <= stk.top().first)
				stk.pop();
			left[i] = stk.top().second;
		}
		stk.push({heights[i], i});
	}
	return left;
}
/*
Nearest Smaller to right : if it does not exist we will put (n) there
*/
vector<int> NSR(vector<int>& heights)
{
	int n = heights.size();
	vector<int> right(n, 0);
	stack<pair<int, int>> stk;
	stk.push({ -1, n });
	for (int i = n - 1; i >= 0; i--)
	{
		if (heights[i] > stk.top().first)
		{
			right[i] = stk.top().second;
		}
		else
		{
			while (heights[i] <= stk.top().first)
				stk.pop();
			right[i] = stk.top().second;
		}
		stk.push({heights[i], i});
	}
	return right;
}

int largestRectangleArea(vector<int>& heights)
{
	if (heights.size() == 0)
		return 0;
	vector<int> nsl = NSL(heights);
	vector<int> nsr = NSR(heights);

	int maxArea = (nsr[0] - nsl[0] - 1) * heights[0];

	for (int i = 1; i < heights.size(); i++)
	{
		maxArea = max(maxArea, heights[i] * (nsr[i] - nsl[i] - 1));
	}
	return maxArea;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> heights(n);
	for (int i = 0; i < n; i++)
		cin >> heights[i];

	int ans = largestRectangleArea(heights);
	cout << ans << "\n";
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
