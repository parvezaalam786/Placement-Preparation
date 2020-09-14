#include<bits/stdc++.h>
using namespace std;
// https://www.interviewbit.com/problems/find-permutation/
/*
D = The next number is smaller than the current element
I = The next number is greater than the current element
The idea is simple:
 If A[i] == 'I':
    we will pick the smallest number from the remaining set of elements
 If A[i] == 'D':
    we will pick the largest number from the remaining set of elements
*/

vector<int> findPerm(const string A, int B)
{
    set<int> s1;
    for (int i = 1; i <= B; i++)
        s1.insert(i);

    vector<int> ans;
    for (auto i : A)
    {
        if (i == 'I')
        {
            auto it = s1.begin();
            ans.push_back(*it);
            s1.erase(it);
            // for (auto x : s1)
            //     cout << x << " ";
            // cout << "\n";
        }
        else
        {
            auto it = s1.end();
            it--;
            ans.push_back(*it);
            s1.erase(it);
            // for (auto x : s1)
            //     cout << x << " ";
            // cout << "\n";
        }
    }
    ans.push_back(*s1.begin());
    return ans;
}

int main()
{
    string s;
    cin >> s;
    vector<int> ans = findPerm(s, s.length() + 1);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}