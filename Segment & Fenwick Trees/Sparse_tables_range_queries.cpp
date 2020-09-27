///This sparse table is for maximum element query
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL);
#define input freopen("Test.txt","r",stdin)
#define output freopen("Output.txt","w",stdout);
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define pi 2*acos(0.0)
#define pb push_back
#define eb emplace_back

#define MAX 200

ll lookup[MAX][MAX];

void buildSparseTable(ll arr[],ll n)
{
    for(int i=0;i<n;i++)
        lookup[i][0] = arr[i];
    for(ll j=1;(1<<j)<=n;j++)
    {
        for(ll i=0;(i+(1<<j)-1)<n;i++)
        {
            if(lookup[i][j-1]<lookup[i+(1<<(j-1))][j-1])
                lookup[i][j] = lookup[i][j-1];
            else
            {
                lookup[i][j] = lookup[i+(1<<(j-1))][j-1];   
            }
            
        }   
    }
}

ll query(ll L,ll R)
{
    ll j = (int)log2(R-L+1);
    if (lookup[L][j] <= lookup[R - (1 << j) + 1][j]) 
        return lookup[L][j]; 
  
    else
        return lookup[R - (1 << j) + 1][j]; 
}
int main()
{
    fast_io;
    //input;
    //output;
    ll N; cin>>N;
    ll input_arr[N];
    for(int i=0;i<N;i++) cin>>input_arr[i];

    buildSparseTable(input_arr,N);
    ll M,x,y; cin>>M;
    for(int i=0;i<M;i++)
    {
        cin>>x>>y;
        ll ans = query(x,y);
        cout <<ans<< endl;
    }
    return 0;
}