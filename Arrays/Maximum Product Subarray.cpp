#include<bits/stdc++.h>
using namespace std;
/*
Given an integer array nums, find the contiguous subarray within an array (containing at least one number)
which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray
*/

/*
For finding the maximum product, since all the numbers are integer, so we know that the product would be maximum
when either we multiply the negative number with a negative number or positive number with a positive number.

If the negative number comes, then we should swap our maximum product with minimum, because it will now make the
maximum product minimum.
For example, mx=4 and mn=-2 and nums[i]=-2., then the larger number would now become smaller then smaller number.
*/
int maxProduct(vector<int>& nums)
{
	int n = nums.size();
	int ans = nums[0];
	int mx = nums[0], mn = nums[0];
	for (int i = 1; i < n; i++)
	{
		if (nums[i] < 0)
			swap(mx, mn);
		mx = max(nums[i], nums[i] * mx);
		mn = min(nums[i], nums[i] * mn);
		ans = max(ans, mx);
	}
	return ans;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	int prod = maxProduct(nums);
	cout << prod;
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
