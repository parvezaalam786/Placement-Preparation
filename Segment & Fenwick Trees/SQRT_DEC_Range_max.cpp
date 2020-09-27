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
#define int_max 9999999999

ll arr[100000];
ll block[1000];
ll blk_size;

ll query(ll l,ll r)
{
    ll ans = INT_MIN;
    while(l<r and l%blk_size!=0 and l!=0)
    {
        ans = max(ans,arr[l]);
        l++;
    }
    while(l+blk_size<=r)
    {
        ans = max(ans,block[l/blk_size]);
        l += blk_size;
    }
    while(l<=r)
    {
        ans = max(ans,arr[l]);
        l++;
    }
    return ans;
}
void preprocess(ll input_arr[],ll n)
{
    ll block_idx = -1;
    blk_size = sqrt(n);
    for(int i=0;i<n;i++)
    {
        arr[i] = input_arr[i];
        if(i%blk_size==0)
        {
            block_idx++;
        }
        block[block_idx] = max(block[block_idx],arr[i]);
    }
}

int main()
{
     fast_io;
    // output;
    ll N; cin>>N;
    ll input_arr[N];
    for(int i=0;i<N;i++) cin>>input_arr[i];

    memset(block,INT_MIN,sizeof(block));
    preprocess(input_arr,N);

    ll M,x,y; cin>>M>>x>>y;
    ll ans = query(min(x,y),max(x,y));
    for(int i=1;i<M;i++)
    {
        x = (x+7)%(N-1);
        y = (y+11)%N;
        ans += query(min(x,y),max(x,y));
    }
    cout <<ans<< endl;     
    return 0;
}