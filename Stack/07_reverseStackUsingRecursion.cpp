#include <iostream>
#include <stack>
using namespace std;

//work is to push only one element at bottom
void insertAtBottom(stack<int>&s, int element)
{
    //base case
    if (s.empty())
    {
        s.push(element);
        return;
    }
    int num = s.top();
    s.pop();

    //recursive call
    insertAtBottom(s, element);

    s.push(num);
    
}



void reverseStack(stack<int> &stack){
    //base case
    if (stack.empty())
    {
       return; 
    }

    int  num = stack.top(); //the order of the element will never change if they are getting stored here it will be in the same position as they were in stack, and when they will be passed to another function they will be passed in the same way as they were passed during the formation of their parent stack
    stack.pop();

    //recursive call

    reverseStack(stack);

    insertAtBottom(stack,num);

}

void Print(stack<int>&stack)
{
    while (!stack.empty())
    {
        cout<<stack.top()<<" ";
        stack.pop();
    }
    
    
}

//sab bahar fek do 
//then jab wapas dalonge 
// toh joh element tune first meh nikala hoga usko sabse last meh insert karde 
 
int main()
{
    stack<int>n;
    n.push(2);
    n.push(3);
    n.push(4);
    n.push(5);

    Print(n);
    reverseStack(n);
    Print(n);
    
    return 0;
}