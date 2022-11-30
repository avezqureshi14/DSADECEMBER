#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int minCost(string &str)
{
    if (str.size() % 2 == 1)
    {
        return -1;
    }
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {

        char ch = str[i];
        if (ch == '{')
        {
            s.push(ch);
        }
        else
        {
            // if ch is closed bracket
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }

    int a = 0, b = 0;
    while (!s.empty())
    {
        if (s.top() == '{')
        {
            b++;
        }
        else
        {
            a++;
        }
        s.pop();
    }

    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}
int main()
{
    string s = "}}}{}{}}}}";

    cout << "Minmum Cost for Finding the Valid String is " << minCost(s) << endl;

    return 0;
}