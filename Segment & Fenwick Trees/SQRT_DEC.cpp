//This is for finding the sum of the given range in the array. 
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

int arr[100000];
int block[1000];
int blk_size;

void update(int idx,int val)
{
    int blockNumber = idx/blk_size;
    block[blockNumber] += val-arr[idx];
    arr[idx] = val;
}

int query(int l,int r)
{
    int sum = 0;
    while(l<r and l%blk_size!=0 and l!=0)
    {
        sum += arr[l];
        l++;
    }
    while(l+blk_size<=r)
    {
        sum += block[l/blk_size];
        l += blk_size;
    }
    while(l<=r)
    {
        sum += arr[l];
        l++;
    }
    return sum;
}

void preprocess(int input_arr[],int n)
{
    int block_idx = -1;
    blk_size = sqrt(n);
    for(int i=0;i<n;i++)
    {
        arr[i] = input_arr[i];
        if(i%blk_size==0)
        {
            block_idx++;
        }
        block[block_idx] += arr[i];
    }
}

int main()
{
    //fast_io;
    //input;
    //output;
    int input_arr[] = {1, 5, 2, 4, 6, 1, 3, 5, 7, 10}; 
    int n = sizeof(input_arr)/sizeof(input_arr[0]); 
    
    memset(block,0,sizeof(block));
    preprocess(input_arr, n); 
  
    cout << "query(3,8) : " << query(3, 8) << endl; 
    cout << "query(1,6) : " << query(1, 6) << endl; 
    update(8, 0); 
    cout << "query(8,8) : " << query(8, 8) << endl; 
    return 0; 
}


