// Handshaking Lemma
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a,sum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        sum+=a;
    }
    if(sum == 2*(n-1))
        printf("Yes\n");
    else
        cout<<"No\n";

    return 0;

}
