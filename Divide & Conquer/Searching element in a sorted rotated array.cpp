#include<iostream>
using namespace std;
int searchIn(int arr[],int s,int e,int ele)
{
    ///Base case
    if(s>e)
        return -1;
    ///Recursive case
    int mid = (s+e)/2;
    if(arr[mid]==ele)
        return mid;
    ///left part of the pivot
    if(arr[s]<=arr[mid])
    {
        if(arr[s]<=ele&&arr[mid]>=ele)
        {
            return searchIn(arr,s,mid-1,ele);
        }
        else
        {
            return searchIn(arr,mid+1,e,ele);
        }
    }
    ///right part of the pivot
    if(ele>=arr[mid]&&ele<=arr[e])
    {
        return searchIn(arr,mid+1,e,ele);
    }
    return searchIn(arr,s,mid-1,ele);
}


int main()
{
    int arr[] = {5,6,7,8,9,10,11,12,1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    int s=0,end=n-1,mid;
    int ele = 1;
    cout<<searchIn(arr,s,end,ele)<<endl;;
    return 0;
}
