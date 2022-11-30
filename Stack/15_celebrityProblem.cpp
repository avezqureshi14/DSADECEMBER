#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool knows(vector<vector<int>> &M, int a, int b, int n)
{
    if (M[a][b] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> s;
    // Step-1 Push all elements in stack
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    // step2- get two elements and compare them

    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (knows(M, a, b, n))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    int ans = s.top();
    // Step-3 Single Element in Stack is Potential Celebrity
    // So verify it

    int zeroCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[ans][i] == 0)
        {
            zeroCount++;
        }
    }
    // all zeroes
    if (zeroCount != n)
    {
        return -1;
    }

    // column check
    int oneCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (M[i][ans] == 1)
        {
            oneCount++;
        }
    }

    if (oneCount != n - 1)
    {
        return -1;
    }

    return ans;
}
int main()
{
    vector<vector<int>> M;
    vector<int> m1;
    m1.push_back(0);
    m1.push_back(1);
    m1.push_back(0);
    vector<int> m2;
    m2.push_back(0);
    m2.push_back(0);
    m2.push_back(0);
    vector<int> m3;
    m3.push_back(0);
    m3.push_back(1);
    m3.push_back(0);
    M.push_back(m1);
    M.push_back(m2);
    M.push_back(m3);

    int n = M.size();
    cout << "So the Celebrity is " << celebrity(M, n);
    return 0;
}