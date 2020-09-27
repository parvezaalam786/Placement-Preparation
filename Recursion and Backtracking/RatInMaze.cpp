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
int min(int x,int y){ if(x<y) return x; return y; }
int max(int x,int y){ if(x<y) return y; return x; }

bool RatInMaze(char maze[10][10],int soln[][10],int i,int j,int m,int n)
{  
    if(i==m and j==n)
    {
        soln[m][n] = 1;
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                cout<<soln[i][j]<<" ";
            }
            cout<<"\n";
        }
        return true;
    }

    //Rat should be inside grid
    if(i>m || j>n)
    {
        return false;
    }
    if(maze[i][j] == 'X')
    {
        return false;
    }
    soln[i][j] = 1;
    bool right = RatInMaze(maze,soln,i,j+1,m,n);
    bool left = RatInMaze(maze,soln,i+1,j,m,n);
    soln[i][j] = 0;
    if(right||left)
    {
        return true;
    }
    return false;

}

void solve()
{
    char maze[10][10] = {
                            "0000",
                            "00X0",
                            "000X",
                            "0X00",
    };
    int soln[10][10] = {0};
    int m = 4,n = 4;

    bool ans = RatInMaze(maze,soln,0,0,m-1,n-1);
    if(ans == false)
        cout<<"Path does not exist";

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