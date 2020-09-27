#include<bits/stdc++.h>
using namespace std;
char spelling[][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
void print(int n)
{
    if(n==0)
    return;
    print(n/10);
    int i = n%10;
    cout<<spelling[i]<<" ";
}

int main()
{
    int n;
    cin>>n;
    print(n);
    return 0;
}