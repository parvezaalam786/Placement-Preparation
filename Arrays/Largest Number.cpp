/*
https://www.interviewbit.com/problems/largest-number/
*/

bool cmp(string a, string b)
{
    string ab = a.append(b);
    string ba = b.append(a);
    return ab.compare(ba) > 0 ? 1 : 0;
}
string Solution::largestNumber(const vector<int> &A)
{
    vector<string> arr;
    for (int i = 0; i < A.size(); i++)
        arr.push_back(to_string(A[i]));
    sort(arr.begin(), arr.end(), cmp);
    string ans = "";
    for (int i = 0; i < arr.size(); i++)
    {
        ans += arr[i];
    }
    if (ans[0] == '0')
        ans = "0";
    return ans;
}
