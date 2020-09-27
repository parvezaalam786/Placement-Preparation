#include<bits/stdc++.h>
using namespace std;
vector<string> arr;
string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };
string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void helper(string input, string output)
{
	if(input.length()==0)
	{
		arr.push_back(output);
		return;
	}
	string temp = table[input[0]-'0'];
	for(int i=0; i<temp.length(); i++)
		helper(input.substr(1), output + temp[i]);
}

int main() {
	string str; cin>>str;
	helper(str, "");
	for(int i=0; i<11; i++)
	{
		for(auto j: arr)
		{
			if(searchIn[i].find(j)!=string::npos)
				cout<<searchIn[i]<<endl;
		}
	}
	// for(int i=0; i<11; i++)
	// 	cout<<reff[i]<<" ";
	// cout<<endl;
	return 0;
}