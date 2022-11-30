#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Do application  of merge sort from GFG it is very very important for placements 
void merge(int arr[], int s, int e){
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k++];
    }
    
    //merge 2 sorted arrays
    int i = 0;
    int j = 0;
    k = s;

    while (i < len1 && j < len2)
    {
      if (first[i] < second[j])
      {
        arr[k++] = first[i++];
      }
      else{
        arr[k++] = second[j++];
      }
         
    }

    while (i < len1)
    {
        arr[k++] = first[i++];
    }
    while (j < len2)
    {
        arr[k++] = second[j++];
    }
    
    
    
}


void mergeSort(int arr[], int s, int e){
    //base case
    if (s>=e)
    {
        return;
    }

    int mid = s + (e-s) / 2;

    //sort left part
    mergeSort(arr,s,mid);

    //sort right part
    mergeSort(arr,mid + 1,e);

    //merge
    merge(arr,s,e);
    
}

void print(int arr[], int n ){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
int main()
{
    int arr[5] = {2,15,1,60,-9};
    int n = 5;
    mergeSort(arr,0,n-1);
    print(arr,n);
    
    return 0;
}