#include<bits/stdc++.h>
using namespace std;
#define ll long long
int p[1000002] = {0};
void Sieve(){
    for(int i=0;i<=1000000;i++)
        p[i] = 1;
    p[0]=p[1]=0;    
    for(int i=2;i<=1000000;i++){
        if(p[i]){
            for(int j=2*i;j<=1000000;j+=i)
                p[j]=0;
        }
    }
}
int segmented_sieve(ll a,ll b){
    Sieve();
    bool pp[b-a+1];
    memset(pp,1,sizeof(pp));
    for(ll i=2;i*i<=b;i++){
        for(ll j=a;j<=b;j++){
            if(p[i]){
                if(j==i)
                    continue;
                if(j%i==0)
                    pp[j-a] = 0;    
            }
        }
    }
    int res = 0;
    for(ll i=a;i<b;i++){
        res+=pp[i-a];
    }
    return res;
}
int main()
{
    int T; cin>>T;
    while(T--)
    {
        ll a,b;
        cin>>a>>b;
        int res = segmented_sieve(a,b);
        cout<<res<<endl;    
    }
    
    return 0;
}