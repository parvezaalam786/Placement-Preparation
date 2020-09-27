#include <bits/stdc++.h>
using namespace std;

float findMedianSortedArrays(int arr1[], int arr2[], int n1, int n2)
{
    if (n1 > n2)
    {
        return findMedianSortedArrays(arr2, arr1, n2, n1);
    }
    int x = n1;
    int y = n2;
    int low = 0;
    int high = x;
    while (low <= high)
    {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        //if partitionX is 0 it means there is nothing on left side .Use -INF for max side of maxLeftX
        //if partitionX is length of input then there is nothing on right side. Use +INF for minRightX
        int maxLeftX = (partitionX == 0) ? INT_MIN : arr1[partitionX - 1];
        int minRightX = (partitionX == x) ? INT_MAX : arr1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : arr2[partitionY - 1];
        int minRightY = (partitionY == y) ? INT_MAX : arr2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX)
        {
            //We have partitioned array at correct place
            //Now get max off left elements and min of right elements to get the median in case of even length combined array size 
            //or get max of left elements in case of odd combined array size 
            if ((x + y) % 2 == 0)
            {
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
            }
            else
            {
                return max(maxLeftX, maxLeftY);
            }
        }
        else if (maxLeftX > minRightY)//we are too far on right side of parttionX ,,,Go on left side
        {
            high = partitionX - 1;
        }
        else//We are too far on left side for partitionX,,,move go right side
        {
            low = partitionX + 1;
        }
    }
}
int main()
{
    int arr1[] = {1,3,8,9,15};
    int arr2[] = {7,11,18,19,21,25};

    int n1 = sizeof(arr1)/sizeof(int);
    int n2 = sizeof(arr2)/sizeof(int);

    cout<<"Median "<<findMedianSortedArrays(arr1,arr2,n1,n2);
    return 0;
}