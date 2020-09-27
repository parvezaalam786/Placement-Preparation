#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    //Base Case
    if(n==1){
        return;
    }
    //Sort 1 element and call for remaining n-1 elements
    for(int j=0;j<=n-2;j++)
    {
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
    }
    bubbleSort(arr,n-1);
}

void bubbleSort2(int arr[],int j,int n){
    //Base Case
    if(n==1){
        return;
    }
    if(j==n-1){
        return bubbleSort2(arr,0,n-1);
    }
    //Rec case
    if(arr[j]>arr[j+1]){
        swap(arr[j],arr[j+1]);
    }
    bubbleSort2(arr,j+1,n);
    return;
}

int main()
{
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(int);
    //bubbleSort(arr,n);
    bubbleSort2(arr,0,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
