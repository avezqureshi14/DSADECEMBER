// Very Important
//Read theory of QuickSort

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    // place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // left and right wala part
    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    // partition
    int p = partition(arr, s, e);

    // sort left part
    quickSort(arr, s, p - 1);

    // sort right part
    quickSort(arr, p + 1, e);
}


void print(int arr[], int n ){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
int main()
{
    int arr[] = {2,15,1,60,-9};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    print(arr,n);

    return 0;
}

// take a pivot
// count all elements < pivot
// pivot -> start + count