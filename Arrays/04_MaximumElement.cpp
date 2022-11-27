#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void maximum(vector<int> &nums)
{
    int n = nums.size();
    int max, min;
    if (n == 1)
    {
        max = nums[0];
        min = nums[0];
    }
    else
    {
        if (nums[0] > nums[1])
        {
            max = nums[0];
            min = nums[1];
        }
        else
        {
            max = nums[1];
            min = nums[0];
        }

        for (int i = 2; i < n; i++)
        {
            if (nums[i] > max)
            {
                max = nums[i];
            }
            if (nums[i] < min)
            {
                min = nums[i];
            }
        }
    }
    cout<<"Maximum and Minimum Element is "<<max<<", "<<min;
}
int main()
{
    vector<int> nums;
    nums.push_back(22);
    nums.push_back(2);
    nums.push_back(12);
    nums.push_back(5);
    nums.push_back(9);
    maximum(nums);
    return 0;
}