#include<bits/stdc++.h>
using namespace std;

void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << "\n";
}


void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
    printarr(arr, n);
}

void insertionSort(int arr[], int n)
{

    int key;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        int j = i - 1;
        while (j >= 0 and arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    printarr(arr, n);
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int mn_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mn_idx])
                mn_idx = j;
        }
        swap(arr[i], arr[mn_idx]);
    }
    printarr(arr, n);
}

/*************QUICK SORT**************/

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];

    int i = (low - 1);
    for (int j = low; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}
/*************************************/


/*****************MERGE SORT********************/

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[m + j + 1];

    i = 0, j = 0, k = l;

    while (i < n1 and j < n2)
    {
        if (L[i] <= R[i])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++; k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++; k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

/***********************************************/
int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = 5;
    // bubbleSort(arr, n);
    // insertionSort(arr, n);
    // selectionSort(arr, n);

    // quickSort(arr, 0, n - 1);
    // printarr(arr, n);

    mergeSort(arr, 0, n - 1);
    printarr(arr, n);

    return 0;
}