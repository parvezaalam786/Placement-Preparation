#include<bits/stdc++.h>
using namespace std;
#define ll          long long int
#define endl        "\n"
#define fast_io     ios::sync_with_stdio(false);cin.tie(NULL);
#define input       freopen("Test.txt","r",stdin)
#define output      freopen("Output.txt","w",stdout);
#define what_is(x)  cout<<#x<<" is "<<x<<endl;
#define pb          push_back
#define eb          emplace_back
#define inf         1000000000
const double pi = 3.141592653589793238460;
#define mod 1000000007

int findSubarraySum(int arr[],int n,int sum)
{
  unordered_map<int,int> m1;
  int res = 0, currsum = 0;
  for(int i=0;i<n;i++)
  {
    currsum += arr[i];
    if(currsum==sum)
      res++;
    if(m1.find(currsum-sum)!=m1.end())
      res += m1[currsum-sum];
      
    m1[currsum]++;
  }
  return res;  
}

int main()
{
    fast_io;
    ///input;
    ///output;
    int arr[] = {10,2,-2,-20,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 0;
    cout<<findSubarraySum(arr,n,sum)<<endl;
    
    int arr1[] = {9, 4, 20, 3, 10, 5};
    n = sizeof(arr1)/sizeof(arr1[0]);
    sum = 33;
    cout<<findSubarraySum(arr1,n,sum)<<endl;
    
        
    return 0;
}