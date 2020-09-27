#include<bits/stdc++.h>
using namespace std;

int _mergeSort(int arr[],int temp[],int left,int right);
int merge(int arr[],int temp[],int left,int mid,int right);

int mergeSort(int arr[],int n)
{
    int temp[n];
    return _mergeSort(arr,temp,0,n-1);
}

int _mergeSort(int arr[],int temp[],int left,int right)
{
    int mid,ans=0;
    if(right>left)
    {
        mid=(right+left)/2;
        ans += _mergeSort(arr,temp,left,mid);
        ans += _mergeSort(arr,temp,mid+1,right);
        
        ans += merge(arr,temp,left,mid+1,right);
    }
    return ans;
}

int merge(int arr[],int temp[],int left,int mid,int right)
{
    int i,j,k;
    int count = 0;
    i = left;
    j = mid;
    k = left;

    while((i<=mid-1)&&(j<=right))
    {
        if(arr[i]<=arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            count = count + (mid-i);
        }
    }
    while(i<=mid-1)
    {
        temp[k++] = arr[i++];
    }
    while(j<=right)
    {
        temp[k++] = arr[j++];
    }
    for(i=left;i<=right;i++)
    {
        arr[i] = temp[i];
    }
    return count;
}


int main()
{
    int arr[] = {1,20,6,4,5};
    int n = sizeof(arr)/sizeof(int);
    int ans = mergeSort(arr,n);
    cout<<"Number of inversions are "<<ans<<endl;
    return 0;

}
