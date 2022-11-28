#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*prev;
    Node*next;

    //construnctor
    Node(int val){
        this->data = val;
        this->prev = NULL;
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

int getLength(Node*&head){
    int len = 0;
    Node*temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp -> next;
    }

    return len;
    
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(11);
    Node *third = new Node(12);
    head->next = second;
    second->next = third;
    third->next = NULL;
    cout<<"Lenght of the Linked List is "<<getLength(head);
    return 0;
}