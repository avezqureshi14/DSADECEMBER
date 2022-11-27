#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans;
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        if (map.find(target - nums[i]) != map.end())
        {
            ans.push_back(map[target - nums[i]]);
            ans.push_back(i);
            return ans;
        }

        // value    = key
        map[nums[i]] = i; // this is not the else condition you have to insert inside the set even if it is inserted before(duplicates are allowed as they will be replaced) //overwriting is essential for consequtive terms
    }
    return ans;
}

int main()
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);

    for (int i : twoSum(nums, 6))
    {
        cout << i << " ";
    }

    return 0;
}