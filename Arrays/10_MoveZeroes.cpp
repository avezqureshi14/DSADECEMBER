#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int>&nums){
    int nonZero = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[nonZero] );
            nonZero++;
        }
        
    }
    
}
void print(vector<int> &nums)
{
    for (int i : nums)
    {
        cout << i << " ";
    }
}



int main()
{
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(10);
    nums.push_back(0);
    nums.push_back(15);
    moveZeroes(nums);
    print(nums);
    return 0;
}