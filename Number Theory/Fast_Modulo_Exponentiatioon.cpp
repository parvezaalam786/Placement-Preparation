#include<iostream>
using namespace std;
#define ll long long 

ll fastModExpo(ll a,ll b,ll m)
{
    ll res = 1;
    while(b>0)
    {
        if(b&1){
            res = (res*a)%m;
        }
        a = (a*a)%m;
        b = b>>1;
    }
    return res;
}
int main()
{
    cout<<fastModExpo(2,10,2000);
    return 0;
}