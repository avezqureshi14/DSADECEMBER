#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void insertInSorted(stack<int> &s, int element)
{
    if (s.empty() || s.top() <= element)
    {
        s.push(element);
        return;
    }
    int store = s.top();
    s.pop();
    insertInSorted(s, element);
    s.push(store);
}


void print(stack<int> s){
    while (!s.empty())
    {
    cout<<s.top()<<" ";
    s.pop();
    }
}


int main()
{
    stack<int>s;
    s.push(1);
    s.push(3);
    s.push(4);
    insertInSorted(s,2);
    print(s);

    
    return 0;
}