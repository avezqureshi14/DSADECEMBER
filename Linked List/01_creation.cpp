#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

void print(Node*&n){
    while (n != NULL)
    {
        cout<<n->data<<"-> ";
        n = n->next;
    }
    
}

int main()
{
    Node*head = new Node(10);
    head->next = NULL;
    print(head);

    return 0;
}