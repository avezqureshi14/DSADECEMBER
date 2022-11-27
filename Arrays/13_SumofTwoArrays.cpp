#include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector<int>findArraySum(vector<int>&a, int n, vector<int>&b, int m){
    int i = n-1;
    int j = m-1;
    vector<int>ans;
    int carry = 0;
    while (i >=0 && j >= 0)
    {
        int val1 = a[i];
        int val2 = b[j];

        int sum = val1 + val2 + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
        j--;
    }


    //first case
    while (i >= 0)
    {
        int sum = a[i] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
    }

    //second case
    while (j >= 0)
    {
        int sum = b[j] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        j--;
    }

    //third case
    while (carry != 0)
    {
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
    }

    reverse(ans.begin(), ans.end());
    return ans;
    
    
    

}


int main()
{
    vector<int>a1;
    a1.push_back(1);
    a1.push_back(2);
    a1.push_back(2);
    int n = a1.size();
    vector<int>a2;
    a2.push_back(1);
    int m = a2.size();
    
    for(auto i : findArraySum(a1,n,a2,m)){
        cout<<i<<" ";
    }

    return 0;
}