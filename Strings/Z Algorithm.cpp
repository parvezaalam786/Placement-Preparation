#include<bits/stdc++.h>
using namespace std;

/*
	Z Algorithm: It is string matching algorithm
	Time Complexity = O(string.length() + pattern.length())

	string = ababaa , pattern = aba

	step1: string tot = pattern + "$" + string
		   => tot = aba$ababaa

	step2: 	  0 1 2 3 4 5 6 7 8 9
		tot = a b a $ a b a b a a
			  i       j				tot[i] = tot[j] i++,j++
			  	i       j			tot[i] = tot[j] i++,j++
			  	  i 	  j			tot[i] = tot[j] i++,j++
			  	    i       j 		tot[i] != tot[j] i++,j++ after encountering $

	Z[] = 0 0 1 0 3 0 3 0 1 1
		  0 1 2 3 4 5 6 7 8 9

	Indicies at which pattern is found
	4-3-1 = 0
	6-3-1 = 2			  	    										 we find that a match has occured
*/

void solve()
{

}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
