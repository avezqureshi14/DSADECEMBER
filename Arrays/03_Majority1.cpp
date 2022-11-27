#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Naivemajority1(vector<int> &nums)
{
    int n = nums.size();
    int count = 1;
    int ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (nums[i + 1] == nums[i])
        {
            count++;
            if (count > n / 2)
            {
                ans = nums[i];
                break;
            }
        }
    }

    return ans;
}

int Optimalmajority1(vector<int> &nums)
{
    int count = 0;
    int major = 0;
    for (int num : nums)
    {
        if (count == 0)
        {
            major = num;
        }
        if (num == major)
        {
            count = count + 1;
        }
        else
        {
            count = count - 1;
        }
    }

    return major;
}

int Bettermajority1(vector<int> &nums)
{
    unordered_map<int, int> map;
    for (auto i : nums)
    {
        map[i]++; //takes the number and store the number of times it had occured in an array
        if (map[i] > nums.size() / 2)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    vector<int> nums;
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(1);
    nums.push_back(8);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(8);
    cout << "Majority Element is " << Optimalmajority1(nums);

    return 0;
}