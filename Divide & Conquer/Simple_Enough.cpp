#include <iostream>
using namespace std;
#define lli long long int
lli right, left;
lli c1 = 0;
lli func(lli n)
{
    if (n == 1)
        return 1;

    if (n == 0)
        return 1;
    lli x = func(n / 2);
    if (n % 2 == 0)
    {
        x = 2 * x + 1;
    }
    else
    {
        x = 2 * x + 1;
    }
    return x;
}
lli l, r;
void func2(lli n, lli left, lli right)
{

    if (n == 1)
    {
        c1++;
        return;
    }
    if (n == 0)
    {
        return;
    }
    lli x = (right - left) / 2;
    if (!((l > left + x - 1) || (r < left)))
    {
        func2(n / 2, left, left + x - 1);
    }
    if (!((l > right) || (r < left + x + 1)))
    {
        func2(n / 2, left + x + 1, right);
    }
    if (((left + x) >= l) && (left + x <= r) && (n % 2 == 1))
    {
        c1++;
    }
}
int main()
{
    lli n;
    cin >> n;
    lli x = func(n);
    //cout<<x;
    cin >> l >> r;
    func2(n, 1, x);
    cout << c1;
}
/*
#include<bits/stdc++.h>
using namespace std;
string str = "";
#define ll long long int
void Parvez(ll n)
{
    if(n==0)
        return;
    Parvez(n/2);
    str+=(n%2==1)?'1':'0';
    Parvez(n/2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n=0,l,r,count=0;
    cin>>n>>l>>r;
    Parvez(n);
    for(ll i=l-1;i<r;i++)
    {
        if(str[i]=='1')
            count++;
    }
   // cout<<str<<"\n";
    cout<<count<<endl;
    return 0;
}
 */