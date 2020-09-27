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
char digit[][10] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void permute(char in[],int i,char out[],int j)
{
    if(in[i]=='\0') 
    {
        out[j] = '\0';
        v1.pb(out);
        return;   
    }
    for(int k=0;digit[in[i]-'0'][k]!='\0';k++)
    {
        out[j] = digit[in[i]-'0'][k];
        permute(in,i+1,out,j+1);        
    }    
}

int main()
{
    fast_io;
    ///input;
    ///output;
    
    char in[200],out[200];
    cin>>in;
    permute(in,0,out,0);
    for(auto it1:v1)
    {
        cout<<it1<<endl;
    }
    return 0;
}