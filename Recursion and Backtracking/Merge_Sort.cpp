/// Merge Sort uses Divide and Conquer
#include<iostream>
using namespace std;
void Merge(int arr[],int s,int e)
{
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = s;
    int n = e-s+10;
    int arr1[n];
    while(i<=mid && j<=e)
    {
        if(arr[i]<arr[j]){
            arr1[k++] = arr[i++];
        }
        else{
            arr1[k++] = arr[j++];
        }
    }
    while(i<=mid){
        arr1[k++] = arr[i++];
    }
    while(j<=e){
        arr1[k++] = arr[j++];
    }
    ///copy all the elements to the original array
    for(int i=s;i<=e;i++){
        arr[i] = arr1[i];
    }
}

void mergeSort(int arr[],int s,int e)
{
    if(s>=e){
        return;
    }
    ///Follow 3 steps
    ///1. Divide
    int mid = (s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    /// Merge the two parts
    Merge(arr,s,e);
}
int main(){
    int arr[] = {122,1,23,10,9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(int);
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
