#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string FirstNonRepeating(string A)
{
    unordered_map<char, int> count;
    queue<int> q;
    string ans = "";
    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];
        // increment count
        count[ch]++;

        // q meh push kardo
        q.push(ch);

        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                // repeating character
                q.pop();
            }
            else
            {
                // non-repeating character milgaya
                ans.push_back(q.front());
                break;
            }
        } 

        if (q.empty())
        {
            ans.push_back('#');
        }
        
    }
    return ans;
}

void print(string s){
    for (int i = 0; i < s.length(); i++)
    {
        cout<<s[i]<<" ";
    }
    
}

int main()
{
    string s;
    s.push_back('a');
    s.push_back('a');
    s.push_back('b');
    s.push_back('c');
    string ans;
    ans = FirstNonRepeating(s);
    print(ans);
    return 0;
}