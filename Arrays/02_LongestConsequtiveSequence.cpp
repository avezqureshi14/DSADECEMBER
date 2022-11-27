#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//unordered set doesn't follows sorted manner
int LCS(vector<int> &nums)
{
    int n = nums.size();
    unordered_set<int> set;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        set.insert(nums[i]);
    }

    for(auto i : set){
        cout<<i<<" ";
    }
    cout<<endl;

    for (int i = 0; i < n; i++)
    {
        if (set.find(nums[i] - 1) == set.end())
        {
            int curr = 1;
            while (set.find(curr + nums[i]) != set.end())
            {
                curr++;
            }
            res = max(res, curr);
        }
    }
    return res;
}

int NaiveLCS(vector<int> &nums)
{
    int count = 0;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (nums[i + 1] == nums[i] + 1)
        {
            count++;
        }
    }

    return count;
}
int main()
{
    vector<int> nums;
    nums.push_back(9);
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(9);
    nums.push_back(10);
    nums.push_back(11);
    nums.push_back(6);
    cout << LCS(nums);
    return 0;
}