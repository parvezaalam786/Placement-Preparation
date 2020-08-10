#include<bits/stdc++.h>
using namespace std;
/*
https://www.interviewbit.com/problems/partitions/
*/
/*
if (sum%3 !=0)
    then we cannot divide the elements into three equal parts
else:
    sum(0,i) = sum(i+1,j) = sum(j+1,n-1)
    if we maintain the cumulative sum of the number of (sum/3) from end(suffix array) then this can help us in calculating our answer
     if sum_at[i] == sum/3 then by adding the number of elements that have sum till i+2 from end will give us our answer
     that's where suffic array comes in.

     our answer is
      if curr_sum == (sum)/3:
         ans += suffic[i+2]
*/

solve(int n, vector<int> &arr)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum % 3 != 0)
        return 0;

    sum = sum / 3;
    int x = 0;
    int cnt[n] = {0};
    for (int i = n - 1; i >= 0; i--)
    {
        x += arr[i];
        if (x == sum)
            cnt[i] = 1;
        else
            cnt[i] = 0;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        cnt[i] += cnt[i + 1];
    }
    int ans = 0;
    x = 0;
    for (int i = 0; i < n - 2; i++)
    {
        x += arr[i];
        if (x == sum)
        {
            ans += cnt[i + 2];
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 3, 0, 3};
    int ans = solve(5, arr);
    cout << ans;
}