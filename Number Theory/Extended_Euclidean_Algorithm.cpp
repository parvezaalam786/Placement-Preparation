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
    int cY = x-(a/b)*y;

    x = cX;
    y = cY;
}
int main()
{
    ExtendedEuclids(18,30);
    cout<<x<<","<<y<<endl;

    return 0;
}
