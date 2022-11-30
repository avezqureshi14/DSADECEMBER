#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> prevSmallerElement(vector<int> &nums, int n){
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);
    for (int i = 0 ; i < n; i++)
    {
        int curr = nums[i];
        while (s.top() >= curr)
        {
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
    
}
int main()
{
    vector<int>nums;
    nums.push_back(3);
    nums.push_back(10);
    nums.push_back(5);
    nums.push_back(1);
    nums.push_back(15);
    nums.push_back(10);
    nums.push_back(7);
    nums.push_back(6);
    int n = nums.size();
    vector<int>ans = prevSmallerElement(nums,n);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}