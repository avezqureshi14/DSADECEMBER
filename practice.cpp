#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isValid(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

char toLower(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool isPalindrome(string s){
    int n = s.size();
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        else{
            start++;
            end--;
        }
        
    }
    return true;
}
//main function
bool CheckPalindrome(string s){
    string str = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (isValid(s[i]))
        {
            str.push_back(s[i]);
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        str[i] = toLower(str[i]);
    }

    return isPalindrome(str);
        
}

int main()
{
    string s = "rac$ a C=ar";
    if( CheckPalindrome(s) == true ){
        cout<<"The given string is Palindrome";
    }
    else{
        cout<<"The given string is not a Palindrome";
    }

    return 0;
}