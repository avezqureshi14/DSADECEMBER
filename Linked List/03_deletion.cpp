#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};


void print(Node *&n)
{
    while (n != NULL)
    {
        cout << n->data << "-> ";
        n = n->next;
    }
    cout << "NULL";
}


void deleteNode(Node* &head, int key){
    Node*temp1 = head;
    Node*temp2 = NULL;

    //if head node itself hold the key
    if (temp1 != NULL && temp1->data == key)
    {
        head = temp1->next;
        delete temp1;
        return;
    }
    else{
        while (temp1 != NULL && temp1->data != key)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }

        //if key dosen't exists in the linked list 
        if (temp1 == NULL)
        {
            cout<<"The given node doesn't exists in the linked list"<<endl;
        }

        //Unlink the node from Linked List
        temp2->next = temp1->next;

        //Free memory
        delete temp1;
        
        
    }
    
}


int main()
{
    Node *head = new Node(10);
    Node *second = new Node(11);
    Node *third = new Node(12);
    head->next = second;
    second->next = third;
    third->next = NULL;

    deleteNode(head,17);

    print(head);
    return 0;
}