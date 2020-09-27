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
vector<string> v1;
unordered_map<int,char> m1;

void permute(char in[],char out[],int n,int i,int j)
{
    if(in[i]=='\0')
    {
      out[j] = '\0';
      v1.pb(out);
      return ;
    }
    if(i<n)
    {
      out[j] = m1[in[i]-'0'];
      permute(in,out,n,i+1,j+1);
    }
    if(i+1<n)
    {
      int num = 10*(in[i]-'0')+(in[i+1]-'0');
      if(num<27)
      {
        out[j] = m1[num];
        permute(in,out,n,i+2,j+1);
      }
    }    
}
int main()
{
    fast_io;
    ///input;
    ///output;
    for(int i=1;i<=26;i++)
    {
      m1[i] = char(i+96);
    }
    char in[100],out[100];
    cin>>in;
    int n = strlen(in);
    permute(in,out,n,0,0);
    cout<<"[";
    int cma = v1.size();
    for(auto i:v1)
    {
      cout<<i;
      if(cma>1)
      {
        cout<<", ";
        cma-=1;
      }      
    }
    cout<<"]"<<endl;
    return 0;
}