#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
	unordered_map<int, int> m1;
	vector<int> ans;
	for (int i = 0; i < nums.size(); i++)
	{
		if (m1.count(target - nums[i]))
		{
			ans.push_back(m1[target - nums[i]]);
			ans.push_back(i);
			break;
		}
		m1[nums[i]] = i;
	}
	return ans;
}
int main()
{
	vector<int> nums = {2, 7, 11, 15};
	int target = 9;

	vector<int> ans = twoSum(nums, target);
	cout << ans[0] << " " << ans[1];
	return 0;
}