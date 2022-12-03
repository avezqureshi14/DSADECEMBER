#include <iostream>
#include <bits/stdc++.h>
using namespace std;

queue<int> reverseFirstKElements(queue<int>q, int k){
    //step 1 : pop first k from q and push into stack
    stack<int>s;
    for (int i = 0; i < k; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    //step 2 : fetch from stack and push into q
    while (!s.empty( ))
    {
        int val = s.top();
        s.pop();
        q.push(val);
    }

    //step 2 : fetch first (n-k) elements from q and push back

    int t  = q.size() - k;
    while (t--)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
    
    
    

}

void print(queue<int>&q){
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    
}

int main()
{
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    queue<int>res = reverseFirstKElements(q,3);
    print(res);
    return 0;
}