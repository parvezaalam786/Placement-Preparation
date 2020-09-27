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

bool checkIfSubarrayWithSumZero(int *arr,int n)
{
    unordered_set<int> s;
    int pre = 0;
    for(int i=0;i<n;i++)
    {
      pre += arr[i];
      if(pre==0 or s.find(pre)!=s.end())
      {
        return true;
      }
      s.insert(pre);
    }
    return false;
}
int main()
{
    fast_io;
    ///input;
    ///output;
    int n; cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    bool b = checkIfSubarrayWithSumZero(arr,n);
    if(b==0)
      cout<<"No"<<endl;
    else
      cout<<"Yes"<<endl;
  
    return 0;
}