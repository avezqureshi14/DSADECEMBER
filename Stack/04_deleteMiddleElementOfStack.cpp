#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(stack<int>&inputStack, int count, int size){
    //base case
    if (count == size/2)
    {
        inputStack.pop();
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    //recursive call
    solve(inputStack,count+1,size);

    //function return karne ke baad yeh line peh land karte hum log
    inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack,int n){
    int count = 0;
    solve(inputStack,count,n);
}

void print(stack<int> &s){
    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    
}
int main()
{
    stack<int>s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    int n = s.size();
    deleteMiddle(s,n);
    print(s);


    return 0;
}