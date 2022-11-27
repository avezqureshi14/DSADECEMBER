#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void print(string &s, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<s[i];
    }
    
}


void help(string &s , int n , int low , int high){
    if (low > high)
    {
        return ;
    }

    help(s,n,low+1,high-1);
    swap(s[low],s[high]);
}

void reverseString(string &s, int n){
    int low = 0;
    int high = n - 1;

    help(s,n,low,high);
}



int main()
{
    string s;
    s = "Avez";
    int n = s.length();
    reverseString(s,n);
    print(s,n);

    return 0;
}