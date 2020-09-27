

// https://www.geeksforgeeks.org/length-of-the-longest-valid-substring/
#include<bits/stdc++.h>
using namespace std;
int LongestValidSubstring(string s1)
{	stack<char> stck;
	int n = s1.length();
	int ans = 0;
	stck.push(-1);
	for(int i=0;i<n;i++)
	{
		if(s1[i]=='(')
			stck.push(i);
		else
		{
			if(stck.top()==-1)
				continue;
			stck.pop();
			if(!stck.empty())
			{
				ans = max(ans,i-stck.top());
			}
		}
	}
	return ans;
}


int main()
{
	string s1;
	cin>>s1;
	int ans = LongestValidSubstring(s1);
	cout<<ans<<"\n";
	return 0;
}

