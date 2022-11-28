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


//Treversal of the Linked List
void print(Node*&n){
    while (n != NULL)
    {
        cout<<n->data<<"-> ";
        n = n->next;
    }
    
}


//get the length of the Linked List
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

//insertion at head of the Linked List
void insertAtHead(Node* &head, int new_data){
    Node*temp = new Node(new_data);
    temp->next = head;
    head->prev = temp;
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
    new_node->prev = last;
}


//insert after a given node
void insertAfter(Node* &prev_node, int new_data){
    Node*new_node = new Node(new_data);

    //Jo pehle ka prev_node ka next tah usko abhi new_node ka next banao
    //naya           //pehle
    new_node->next = prev_node->next;
    new_node->prev = prev_node;
    
    //Aur abhi prev_node ka next kaun rahega ? Ans: new_node
    prev_node->next = new_node;
}


//deletion in doubly linked list || Once from codeWithHarry
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
    insertAtHead(head,9);
    insertAtEnd(head,13);
    insertAfter(third,110);
    print(head);
    cout<<"Lenght of the Linked List is "<<getLength(head);
    return 0;
}