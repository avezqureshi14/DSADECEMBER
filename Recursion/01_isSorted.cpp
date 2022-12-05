#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n){
    if (n == 1 || n == 0)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    else{
       return  isSorted(arr+1,n-1);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 44, 5, 6, 7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    if (isSorted(arr,n)){
        cout<<"Array is Sorted"<<endl;
    }
    else{
        cout<<"Array is not Sorted"<<endl;
    }
    
    return 0;
}
