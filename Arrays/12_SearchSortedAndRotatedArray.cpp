#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int search(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    long int mid = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] >= arr[low])
        {
            /* left half sorted */
            if (target >= arr[low] && target < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            /* right half is sorted */
            if (target > arr[mid] && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int>nums;
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    int ans = search(nums,5);
    cout<<"The position of the element in the array is "<<ans;
    return 0;
}