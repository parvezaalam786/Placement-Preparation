#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL);
#define input freopen("Test.txt","r",stdin)
#define output freopen("Output.txt","w",stdout);
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define F(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define eb emplace_back
#define inf 1000000000
const double pi = 3.141592653589793238460;
#define debug false
#define mod 1000000007

struct point
{
	int n,s;
};

bool cmp(struct point a,struct point b)
{
	if(a.s==b.s)
	{
		return a.n<b.n;
	}
	return a.s<b.s;
}
struct point coord[1010];
int x[1010],y[1010];
int n1;

int brides()
{
	int lis[n1];
	for(int i=0;i<n1;i++)
		lis[i] = 1;
	sort(coord,coord+n1,cmp);

	// for(int i=0;i<n1;i++)
	// {
	// 	cout<<coord[i].n<<" "<<coord[i].s<<"\n";
	// }

	for(int i=1;i<n1;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(coord[i].n>=coord[j].n && lis[i]<lis[j]+1)
			{
				lis[i] = lis[j]+1;
			}
		}
	}
	// for(int i=0;i<n1;i++)
	// 	cout<<lis[i]<<" ";

	int ans = lis[0];
	for(int i=1;i<n1;i++)
	{
		ans = max(ans,lis[i]);
	}
	return ans;

}
void solve()
{
	int T; cin>>T;
	while(T--)
	{
		cin>>n1;
		for(int i=0;i<n1;i++)
			cin>>x[i];
		for(int i=0;i<n1;i++)
			cin>>y[i];
		for(int i=0;i<n1;i++)
		{
			coord[i].n = x[i];
			coord[i].s = y[i];
		}

		int ans = brides();
		cout<<ans<<"\n";
	}	
}

int main()
{
    // fast_io;  // output; // if(debug){watch_is();}
    // input;
	solve();   
    return 0;
}