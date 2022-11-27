#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void reverseArray(vector<int> &nums)
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        int temp = nums[right] ;
        nums[right] = nums[left];
        nums[left] = temp;
        left++;
        right--;
    }
}

void print(vector<int>&nums){
    for(auto i : nums){
        cout<<i<<" ";
    }
}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    cout<<endl;
    cout<<"Before reverse"<<endl;
    print(nums);
    cout<<endl;
    cout<<"After reverse"<<endl;
    reverseArray(nums);
    print(nums);

    return 0;
}