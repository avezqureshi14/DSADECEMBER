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

// We are using reference of head pointer because we don't want to create a new copy of our node we want our changes to be carried out in out old node only

void insertAtHead(Node *&head, int new_data)
{
    Node *temp = new Node(new_data);
    temp->next = head;
    head = temp;
}

// insert at end
void insertAtEnd(Node *&head_ref, int new_data)
{
    Node *last;
    Node *new_node = new Node(new_data);
    new_node->next = NULL;

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
}

//insert after a given node
void insertAfter(Node* &prev_node, int new_data){
    Node*new_node = new Node(new_data);
    new_node->next = prev_node->next;
    
    //Jo pehle ka prev_node ka next tah usko abhi new_node ka next banao
    //naya           //pehle
    new_node->next = prev_node->next;
    
    //Aur abhi prev_node ka next kaun rahega ? Ans: new_node
    prev_node->next = new_node;
}


//insert at given position { please watch it from codeWithHarry or GFG }

void print(Node *&n)
{
    while (n != NULL)
    {
        cout << n->data << "-> ";
        n = n->next;
    }
    cout << "NULL";
}

int main()
{
    Node *head = new Node(10);
    head->next = NULL;

    insertAtHead(head, 11);
    insertAtEnd(head,15);
    insertAfter(head,20);
    print(head);
    return 0;
}