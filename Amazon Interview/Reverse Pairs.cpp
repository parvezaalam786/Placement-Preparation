#include<bits/stdc++.h>
using namespace std;


int _merge(vector<int>& nums, int low, int mid, int high)
{
	int cnt = 0;
	int j = mid + 1;

	//counting the pairs
	for (int i = low; i <= mid; i++)
	{
		while (j <= high and nums[i] > 2 * nums[j])
		{
			j++;
		}
		cnt += (j - (mid + 1));	 // +1 because we will be standing at the condition where the rule is broken and we don't want to count the element
	}

	//merging them in sorted form
	vector<int> temp;
	int left = low, right = mid + 1;
	while (left <= mid and right <= high)
	{
		if (nums[left] <= nums[right])
		{
			temp.push_back(nums[left++]);
		}
		else
		{
			temp.push_back(nums[right++]);
		}
	}
	while (left <= mid)
		temp.push_back(nums[left++]);
	while (right <= high)
		temp.push_back(nums[right++]);

	for (int i = low; i <= high; i++)
	{
		nums[i] = temp[i - low];
	}
	return cnt;
}

int mergeSort(vector<int>& nums, int low, int high)
{
	if (low >= high)
		return 0;
	int mid = (low + high) / 2;
	int rev_pairs = mergeSort(nums, low, mid);
	rev_pairs += mergeSort(nums, mid + 1, high);

	rev_pairs += _merge(nums, low, mid, high);
	return rev_pairs;
}

int ReversePairs(vector<int>& nums)
{
	return mergeSort(nums, 0, nums.size() - 1);
}

int main()
{
	vector<int> nums = {1, 3, 2, 3, 1};
	cout << ReversePairs(nums) << "\n";

	vector<int> nums1 = {2, 4, 3, 5, 1};
	cout << ReversePairs(nums1) << "\n";
	return 0;
}