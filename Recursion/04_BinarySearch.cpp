#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool help(int arr[], int n, int low, int high, int key)
{
    if (low > high)
    {
        return false;
    }
    
    int mid = low + (high - low) / 2;
    if (arr[mid] == key)
    {
        return true;
    }

    if (key > arr[mid])
    {
       return help(arr, n, mid + 1, high, key);
    }
    else
    {
       return  help(arr, n, low, mid - 1, key);
    }
}

bool BinarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    return help(arr, n, low, high, key);
}

int main()
{
    int arr[] = {2, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    if(BinarySearch(arr,n,55)){
        cout<<"Found";
    }
    else{
        cout<<"Not Found";
    }
    return 0;
}