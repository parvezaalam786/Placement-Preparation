#include<bits/stdc++.h>
using namespace std;
void dec(int n)
{
    if(n==0){
        return ;
    }
    cout<<n<<" ";
    dec(n-1);
}
void inc(int n)
{
    if(n==0){
        return;
    }
    inc(n-1);
    cout<<n<<" ";
}

int main()
{   inc(5);
    cout<<endl;
    dec(5);
    return 0;
}