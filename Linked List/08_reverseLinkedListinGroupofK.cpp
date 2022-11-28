#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
};

Node*kreverse(Node* &head, int k){
    //base case
    if (head == NULL)
    {
        return NULL;
    }

    //step-1 reverse first k nodes
    Node*next = NULL;
    Node*curr = head;
    Node*prev = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    //step-2 Recursion dekhenga 
    if (next != NULL)
    {
        head -> next = kreverse(next,k);
    }

    //step-3 Return head of reversed list
    return prev;
    
    
    
}

void print(Node* &n){
    while (n != NULL)
    {
        cout<<n->data <<" ";
        n = n->next;
    }
    
}

int main()
{
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();
    Node *five = new Node();
    Node *six = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = five;

    five->data = 5;
    five->next = six;

    six->data = 6;
    six->next = NULL;

    Node*res = kreverse(head,3);
    print(res);


    return 0;
}