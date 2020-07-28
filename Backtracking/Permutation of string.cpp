#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1;
	cin >> s1;
	sort(s1.begin(), s1.end());

	do {
		cout << s1 << "\n";
	}
	while (next_permutation(s1.begin(), s1.end()));
	return 0;
}
/*
cba

abc
acb
bac
bca
cab
cba
*/