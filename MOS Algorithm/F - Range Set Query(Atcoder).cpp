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

// #define BLOCK 707  ///This is for dividing the array into blocks like we do in sqrt decomposition so as to sort them according to the block number
///this is the reason it takes O(sqrt(N)*N) time complexity

int BLOCK;
const int maxn = 500010;
struct query
{
	int l;
	int r;
	int i;
};
query Q[maxn];
int arr[maxn], ans[maxn];
int fre[1000001];
int cnt = 0;

bool comp(query a, query b)
{
	if (a.l / BLOCK != b.l / BLOCK)
		return a.l / BLOCK < b.l / BLOCK;
	return a.r < b.r;
}

void add(int pos)
{
	fre[arr[pos]]++;
	if (fre[arr[pos]] == 1)
		cnt++;
}
void remove(int pos)
{
	fre[arr[pos]]--;
	if (fre[arr[pos]] == 0)
		cnt--;

}
int main()
{
	fast_io;
	//input;
	//output;
	int n, q;
	cin >> n >> q;
	BLOCK = sqrt(n) + 1;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	// cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> Q[i].l >> Q[i].r;
		Q[i].i = i, Q[i].l--, Q[i].r--;
	}

	sort(Q, Q + q, comp);

	int ML = 0, MR = -1;
	for (int i = 0; i < q; i++)
	{
		int L = Q[i].l;
		int R = Q[i].r;

		while (ML > L)
			ML--, add(ML);
		while (MR < R)
			MR++, add(MR);
		while (ML < L)
			remove(ML), ML++;
		while (MR > R)
			remove(MR), MR--;
		ans[Q[i].i] = cnt;
	}

	for (int i = 0; i < q; i++)
		cout << ans[i] << endl;

	return 0;
}
