vector<int> Solution::flip(string A) {
    int len = A.length();
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        if (A[i] == '1')
            arr[i] = -1;
        else
            arr[i] = 1;
    }
    ///using kadane's algorithm
    int sum = 0, l = 0, r = 0, max_sum = 0, l1 = 0, r1 = 0;
    for (int i = 0; i < len; i++)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            l = i + 1;
        }
        else if (sum > max_sum)
        {
            l1 = l;
            max_sum = sum;
            r1 = i;
        }
    }
    vector<int> ans;
    if (max_sum <= 0)
    {
        return ans;
    }
    else {
        ans.push_back(l1 + 1);
        ans.push_back(r1 + 1);
        return ans;
    }
}
