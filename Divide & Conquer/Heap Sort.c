
#include<stdio.h>
#include<stdlib.h>

void Heapify(int arr[],int i,int n)
{
    int largest=i,temp;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l]>arr[largest])
        largest=l;

     if(r<n && arr[r]>arr[largest])
        largest=r;

        if(largest!=i)
        {
            temp=arr[i];
            arr[i]=arr[largest];
            arr[largest]=temp;
             Heapify(arr,largest,n);
        }

}

void HeapSort(int arr[],int N)
{
    int i,temp;
    for(i=(N/2)-1;i>=0;i--)
    Heapify(arr,i,N);
     for (int i=N-1; i>=0; i--)
    {
        temp=arr[i];
        arr[i]=arr[0];
        arr[0]=temp;
        Heapify(arr, 0, i);
    }
}





int main()
{
    int N,i;
    printf("Enter the size of the array : ");
    scanf("%d",&N);
    int arr[N];
    printf("Enter the elements in the array : ");
    for(i=0;i<N;i++)
        scanf("%d",&arr[i]);
    HeapSort(arr,N);
    for(i=0;i<N;i++ )
        printf(" %d",arr[i]);
        return 0;
}
