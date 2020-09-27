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
set<string> ans;

void permute(string arr,string orig,int i)
{
     if(arr[i]=='\0')
     {
          if(arr>orig)
            cout<<arr<<endl;
          return;
     }
     
     for(int j=i;j<arr.length();j++)
     {
          swap(arr[i],arr[j]);
          permute(arr,orig,i+1);
     }     
}

int main()
{
    fast_io;
    ///input;
    ///output;
    string s1;
    cin>>s1;
    string s2 = s1;
    permute(s1,s2,0);
    //for(auto i:ans)
     //cout<<i<<endl;
    return 0;
}