#include<stdio.h>
#include<stdlib.h>


 void Merge(int arr[],int p,int q,int r)
{
  int i,j,k;
    int n1=q-p+1;
        int n2=r-q;
            int arr1[n1],arr2[n2];
  for(i=0;i<n1;i++)
     arr1[i]=arr[p+i];
    for(j=0;j<n2;j++)
        arr2[j]=arr[q+j+1];
     i=0;
       j=0;
         k=p;
     while(i < n1 && j < n2)
     {
         if(arr1[i]<=arr2[j])
         {
             arr[k]=arr1[i];
             i++;
         }
         else
         {
          arr[k]=arr2[j];
          j++;
         }
         k++;
     }
     while(i<n1)
     {
         arr[k] = arr1[i];
           i++;
            k++;
     }
     while(j<n2)
     {
         arr[k] = arr2[j];
          j++;
           k++;
     }
}


 void MergeSort(int arr[],int p,int r)
{
  if(p<r)
  {
      int q=(p+r)/2;
        MergeSort(arr,p,q);
            MergeSort(arr,q+1,r);
                Merge(arr,p,q,r);
  }

}

int main()
{
  int N;
    printf("Enter the number of elements : ");
        scanf("%d",&N);
  int arr[N],i;
    printf("Enter the elements in the array : ");
  for(i=0;i<N;i++)
    scanf("%d",&arr[i]);
        printf("Array is :");
            for(i=0;i<N;i++)
                printf(" %d",arr[i]);
    MergeSort(arr,0,N-1);
                printf("\nSorted Array is : ");
            for(i=0;i<N;i++)
                printf("%d ",arr[i]);
    return 0;
}
