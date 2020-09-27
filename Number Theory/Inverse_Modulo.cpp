#include<bits/stdc++.h>
using namespace std;
int x,y,GCD;
void ExtendedEuclids(int a,int b)
{
    if(b==0)
    {
        x = 1;
        y = 0;
        GCD = a;
        return;
    }
    ExtendedEuclids(b,a%b);
    int cX = y;
    int cY = x - (a/b)*y;
    x = cX;
    y = cY;
}
int InverseModulo(int a,int m)
{
    ExtendedEuclids(a,m);
    return (x+m)%m; //for negative result
}
int main()
{
    cout<<InverseModulo(6,7)<<endl;
    cout<<InverseModulo(18,7)<<endl;
    return 0;
}