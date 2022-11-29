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

void removeDuplicates(Node*head){
    Node*temp1 = head;
    Node*temp2;
    Node*dup;

    while (temp1 != NULL && temp1->next != NULL)
    {
        temp2 = temp1;
        while (temp2->next != NULL)
        {
            if (temp1->data == temp2->next->data)
            {
                dup = temp2->next;
                temp2->next = temp2->next->next;
                delete(dup);
            }
            else{
                temp2 = temp2->next;
            }
        }
    
            temp1 = temp1->next;
    }
    
}


void print(Node* &n){
    while (n != NULL)
    {
        cout<<n->data<<" ";
        n = n -> next;
    }
    
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(2);
    Node *fourth = new Node(3);
    Node *fifth = new Node(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    removeDuplicates(head);
    print(head);
    return 0;
}