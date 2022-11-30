#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isValid(string str)
{
    stack<char> s;
    char ch;
    for (int i = 0; i < str.length(); i++)
    {
        ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else{
            if (!s.empty())
            {
                char top = s.top();
                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[') )
                {
                    s.pop();
                }
                else{
                    return false;
                }
                
            }
            else{
                return false;
            }
            
        }
    }

    if (s.empty())
    {
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    string s = "{{}}";
    bool res = isValid(s);
    if (res == true)
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Unbalanced" << endl;
    }

    return 0;
}

// Time COmplexity O(n)
// Space COmplexity O(n)