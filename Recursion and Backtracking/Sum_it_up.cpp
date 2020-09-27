#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL);
#define input freopen("Test.txt","r",stdin)
#define output freopen("Output.txt","w",stdout);
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define pb push_back
#define eb emplace_back
#define inf 1000000000
const double pi = 3.141592653589793238460;
#define mod 1000000007

set<vector<int>> ans;
vector<int> v1;

void Sum(int arr[],int i,int n,int T,int sum)
{
		if(i>=n)
			return;
		if(sum+arr[i]>T)
			return;
			
		for(int k=i;k<n;k++)
		{
			if(sum+arr[k]<T)
			{
				v1.pb(arr[k]);
				Sum(arr,k+1,n,T,sum+arr[k]);
				v1.pop_back();		
			}
			if(sum+arr[k]==T)
			{
				v1.pb(arr[k]);
				ans.insert(v1);
				v1.pop_back();
			}
		}
}


int main()
{
    fast_io;
    ///input;
    ///output;
    int N;  cin>>N;
    int arr[N];
    for(int i=0;i<N;i++)
    	cin>>arr[i];
	int T;
		cin>>T;
		sort(arr,arr+N);
		
		Sum(arr,0,N,T,0);
		
		for(auto it:ans)
		{
			for(auto it1:it)
			{
				cout<<it1<<" ";
			}
			cout<<endl;
		}
		
    return 0;
}