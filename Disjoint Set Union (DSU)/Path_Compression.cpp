#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define int long long
#define endl "\n"
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define F(i,a,b) for(int i = a; i < b; i++)
#define MAX(a,b,c) max(a,max(b,c))
#define MIN(a,b,c) min(a,min(b,c))
#define pb push_back
#define eb emplace_back
#define inf 1e9
const double pi = 3.141592653589793238460;
#define debug false
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define mod 1000000007
int min(int x, int y) { if (x < y) return x; return y; }
int max(int x, int y) { if (x < y) return y; return x; }
int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}

int par[1000];
int find(int a)
{
    if (par[a] < 0)
        return a;
    return par[a] = find(par[a]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b) return;
    par[a] = b;
}

bool check(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return true;
    return false;
}

void solve()
{
    for (int i = 1; i <= 10; i++)
        par[i] = -i;
    Union(1, 2);
    Union(2, 3);
    Union(2, 4);
    Union(5, 6);
    Union(6, 7);
    Union(7, 8);
    Union(9, 10);

    int a, b;
    for (int i = 0; i < 5; i++)
    {
        cin >> a >> b;
        cout << check(a, b) << "\n";
    }

}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    // if(debug){watch_is();}
    solve();
    return 0;
}
