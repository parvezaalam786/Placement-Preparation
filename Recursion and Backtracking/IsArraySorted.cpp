#include<bits/stdc++.h>
using namespace std;
 bool isSorted(int arr[],int n)
 {
     if(n==1){
         return true;
     }
     if(arr[0]<arr[1] && isSorted(arr+1,n-1)){
         return true;
     }
    return false;
 }


int main()
{
    int arr1[] = {1,2,3,4,5};
    int n = 5;
    cout<<isSorted(arr1,n)<<endl;

    int arr2[] = {1,2,3,8,5};
    cout<<isSorted(arr2,n)<<endl;
    return 0;
}