#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int sum(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return arr[0];
    }
    int remainingPart = sum(arr + 1, n - 1);
    int ans = arr[0] + remainingPart;    
    return ans;
    
}

int main()
{ 
    int arr[] = {2, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<sum(arr,n);
    return 0;
}







