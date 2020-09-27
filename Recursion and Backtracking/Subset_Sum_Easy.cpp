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

bool SubsetSum(int arr[],int n,int i,int sum)
{
     
     if(n==1)
     {
          if(arr[i]==0)
               return true;
          else 
          return false;
     }
          
     if(i>=n)
          return false;     
          
     if(sum+arr[i]==0)
     {
          ///cout<<sum+arr[i]<<endl;
          return true;
     }
          
          
     bool res1 = SubsetSum(arr,n,i+1,sum);          
     if(i+1<n and res1==false)
          {
               bool res2 =  SubsetSum(arr,n,i+1,sum+arr[i]);
               return (res1|res2);
          }
     return res1;
     
     
}
int main()
{
    fast_io;
    ///input;
    ///output;
     int T; cin>>T;
     while(T--)
     {
          int N; cin>>N;
          int arr[N];
          for(int i=0;i<N;i++)
               cin>>arr[i];
          if(SubsetSum(arr,N,0,0))
               cout<<"Yes"<<endl;
          else cout<<"No"<<endl;
     }
    return 0;
}