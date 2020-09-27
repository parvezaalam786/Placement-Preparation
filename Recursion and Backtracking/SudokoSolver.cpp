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

bool canPlace(int mat[][9],int i,int j,int n,int num)
{
    for(int x=0;x<n;x++)
    {
        //Row and colm check
        if(mat[x][j]==num || mat[i][x]==num)
            return false;
    }
    //check in grid
    int rn = sqrt(n);
    int sx = (i/rn)*rn;
    int sy = (j/rn)*rn;
    for(int x=sx;x<sx+rn;x++)
    {
        for(int y=sy;y<sy+rn;y++)
        {
            if(mat[x][y]==num)
                return false;
        }
    }
    return true;
}

bool solveSudoko(int mat[][9],int i,int j,int n)
{
    // Base case
    if(i==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        return true;
    }
    if(j==n)
    {
        return solveSudoko(mat,i+1,0,n);
    }
    //skip the pre-filled cells
    if(mat[i][j]!=0)
    {
        return solveSudoko(mat,i,j+1,n);
    }

    //Rec case
    // fill the current cell with possible options
    for(int num=1;num<=9;num++)
    {
        if(canPlace(mat,i,j,n,num))
        {
            mat[i][j] = num;
            bool couldWeSolve = solveSudoko(mat,i,j+1,n);
            if(couldWeSolve==true)
            {
                return true;
            }
        }
    }
    //Backtrack
    mat[i][j] = 0;
    return false;
}

void solve()
{
    int mat[9][9] = 
        {
            {5,3,0,0,7,0,0,0,0},
            {6,0,0,1,9,5,0,0,0},
            {0,9,8,0,0,0,0,6,0},
            {8,0,0,0,6,0,0,0,3},
            {4,0,0,8,0,3,0,0,1},
            {7,0,0,0,2,0,0,0,6},
            {0,6,0,0,0,0,2,8,0},
            {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,9}
        };

        solveSudoko(mat,0,0,9);
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