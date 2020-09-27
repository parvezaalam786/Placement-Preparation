#include<iostream>
using namespace std;
int main()
{
    int arr[] = {5,6,7,8,9,10,11,12,1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    int s=0,end=n-1,mid;
    while(s<=end)
    {
        mid = (s+end)/2;
        if(mid>s && arr[mid]<arr[mid-1])
            {
                cout<<mid-1<<" ";
                break;
            }
        if(mid<end && arr[mid]>arr[mid+1])
            {
                cout<<mid<<" ";
                break;
            }
        if(arr[s]>=arr[mid])
        {
            end = mid-1;
        }
        else
        {
            s = mid;
        }
    }
    if(s>end)
    {
        cout<<"Pivot element does not exist\n";
    }
    return 0;
}
