#include<iostream>
using namespace std;
void permute(char *a,int i)
{
    //Base Case
    if(a[i]=='\0'){
        cout<<a<<" ";
        return ;
    }
    //Recursive Case
    for(int j=i;a[j]!='\0';j++)
    {
        swap(a[i],a[j]);
        permute(a,i+1);
        //Backtracking to restore the original array
        swap(a[i],a[j]);
    }
    return;
}
int main()
{
    char a[100];
    cin>>a;
    permute(a,0);
    return 0;
}