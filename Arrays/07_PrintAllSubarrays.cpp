#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &nums, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        cout << i << " ";
    }
}

void printAllSubarrays(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            print(nums,i,j);
            cout<<endl;
        }
    }
}

int main()
{
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    printAllSubarrays(nums);
    return 0;
}