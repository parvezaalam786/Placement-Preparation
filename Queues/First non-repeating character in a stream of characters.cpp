#include<bits/stdc++.h>
using namespace std;

/*
https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/
*/

string fun(string str)
{
	queue<char> que;
	unordered_map<char, int> m1;

	string ans = "";
	for (int i = 0; i < str.length(); i++)
	{
		m1[str[i]]++;
		que.push(str[i]);
		while (que.size() > 0)
		{
			if (m1[que.front()] == 1)
			{
				ans.push_back(que.front());
				break;
			}
			que.pop();
		}
		if (que.size() == 0)
			ans.push_back('#');
	}
	return ans;
}

void solve()
{
	string str;
	cin >> str;

	string ans = fun(str);
	cout << ans << "\n";
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
