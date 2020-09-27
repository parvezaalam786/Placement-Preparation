#include<bits/stdc++.h>
using namespace std;
#define ll          long long int
#define endl        "\n"
#define fast_io     ios::sync_with_stdio(false);cin.tie(NULL);
#define input       freopen("Test.txt","r",stdin)
#define output      freopen("Output.txt","w",stdout);
#define what_is(x)  cout<<#x<<" is "<<x<<endl;
#define pb          push_back
#define eb          emplace_back
#define inf         1000000000
const double pi = 3.141592653589793238460;
#define mod 1000000007

int longestSubarrayWithSumZero(int *arr,int n)
{
	unordered_map<int,int> m1;
	int pre = 0;
	int len = 0;
	for(int i=0;i<n;i++)
	{
		pre += arr[i];
		if(arr[i]==0 and len==0) len = 1;
		if(pre==0) len = max(len,i+1);
		if(m1.find(pre)!=m1.end()) 
		{
			len = max(len,i-m1[pre]);
		}
		else 
			m1[pre] = i;
	}
	return len;
}

int main()
{
    fast_io;
    ///input;
    ///output;
  	int n; cin>>n;
  	int *arr = new int[n];
  	for(int i=0;i<n;i++)
  		cin>>arr[i];
		int len = longestSubarrayWithSumZero(arr,n);
		cout<<len<<endl;
    return 0;
}

/*
	input:
	6
	0 -1 1 2 -5 5
	7 
	0 -1 1 2 -5 5 -2
	output:
	3
	7
*/