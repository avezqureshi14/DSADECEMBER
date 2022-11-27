#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int n, int low, int high)
{
    if (n == 0)
    {
        return 0;
    }

    if (s[low] != s[high])
    {
        return 0;
    }

    if (low > high)
    {
        return 1;
    }

    return isPalindrome(s,n,low + 1,high-1);
}

int main()
{
    string s = "opdzar";
    int n = s.length();
    if(isPalindrome(s,n,0,n-1)){
        cout<<"Yes it is a Palindrome";
    }
    else{
        cout<<"Nope!";
    }
    return 0;
}