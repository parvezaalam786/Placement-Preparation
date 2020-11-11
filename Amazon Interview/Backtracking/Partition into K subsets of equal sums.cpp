#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool fun(vector<int>& nums, int subsetsSum[], int K, int currSubset, int setsum, int n, int idx, bool visited[])
    {
        if (subsetsSum[currSubset] == setsum)
        {
            /*  current index (K - 2) represents (K - 1) subsets of equal
            sum last partition will already remain with sum 'setsum'*/
            if (currSubset == K - 2)
                return true;
            return fun(nums, subsetsSum, K, currSubset + 1, setsum, n, n - 1, visited); // starting from the beginning
        }

        for (int i = idx - 1; i >= 0; i--)
        {
            if (visited[i] == true)
                continue;
            int temp = subsetsSum[currSubset] + nums[i];
            if (temp <= setsum)
            {
                visited[i] = true;
                subsetsSum[currSubset] += nums[i];
                bool canFind = fun(nums, subsetsSum, K, currSubset, setsum, n, i, visited);
                visited[i] = false;
                subsetsSum[currSubset] -= nums[i];
                if (canFind)
                    return true;
            }
        }
        return false;
    }


    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        if (k == 1)
            return true;

        int n = nums.size();

        if (k > n)
            return false;

        int sum = 0;

        for (int i = 0; i < n; i++)
            sum += nums[i];

        if (sum % k != 0)
            return false;

        int subsetsSum[k];
        memset(subsetsSum, 0, sizeof(subsetsSum));

        bool visited[n];
        memset(visited, false, sizeof(visited));

        subsetsSum[0] += nums[n - 1];

        int setsum = sum / k;
        return fun(nums, subsetsSum, k, 0, setsum, n, n - 1, visited);

    }
};