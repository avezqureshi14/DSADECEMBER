#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> naiveNGR(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] > nums[i])
            {
                ans.push_back(nums[j]);
                break;
            }
        }
    }
    return ans;
}

// Stack
vector<int> NGR(vector<int> &nums)
{
    int n = nums.size();
    stack<int> s;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
        {
            ans.push_back(-1);
        }
        else if (s.size() > 0 && s.top() > nums[i])
        {
            ans.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() <= nums[i])
        {
            while (s.size() > 0 && s.top() <= nums[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(s.top());
            }
            s.push(nums[i]);
        }
    }

    return ans;
}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);

    for (auto i : NGR(nums))
    {
        cout << i << " ";
    }
    cout << "-1";
    return 0;
}