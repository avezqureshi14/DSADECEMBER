#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool linearSearch(int arr[], int n, int key)
{
    // base case
    if (n == 0)
    {
        return false;
    }
    if (arr[0] == key)
    {
        return true;
    }
    else
    {
        bool remainingPart = linearSearch(arr, n - 1, key);
        return remainingPart;
    }
}

int main()
{
    int arr[] = {2, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (linearSearch(arr, n, 2))
    {
        cout << "Found";
    }
    else
    {
        cout << "Not Found";
    }

    return 0;
}