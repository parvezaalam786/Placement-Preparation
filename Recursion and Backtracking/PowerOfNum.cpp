#include<bits/stdc++.h>
using namespace std;

int power(int a, int n)
{
    if(n==0){
        return 1;
    }
    return a*power(a,n-1);
}

int fastPower(int a,int n)
{
    if(n==0){
        return 1;
    }
    int b = fastPower(a,n/2);
     b*=b;
     if(n&1==1){
         return a*b;
     }
     return b;
}
int main()
{
    cout<<power(2,10)<<endl;
    cout<<fastPower(2,10)<<endl;
    return  0;
}