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

Node *reverseLL(Node *&head_ref)
{
    Node *curr = head_ref;
    Node *prev = NULL;
    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

void insertAtTail(Node *&head, Node *&tail, int val)
{
    Node *temp = new Node(val);

    // empty lists
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

Node *add(Node *&first, Node *&second)
{
    int carry = 0;
    Node *ansHead = NULL;
    Node *ansTail = NULL;
    while (first != NULL && second != NULL)
    {
        int sum = carry + first->data + second->data;

        int digit = sum % 10;

        Node *temp = new Node(digit);
        insertAtTail(ansHead, ansTail, digit);

        carry = sum / 10;
    }

    while (first != NULL)
    {
        int sum = carry + first->data;
        int digit = sum % 10;
        // create node and add in answer linked lists
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
    }

    while (second != NULL)
    {
        int sum = carry + second->data;
        int digit = sum % 10;
        // create node and add in answer linked lists
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
    }

    while (carry != 0)
    {
        int sum = carry;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
    }

    return ansHead;
}

Node *addTwoLists(Node *first, Node *second)
{

    // Step 1 - reverse input LL
    first = reverseLL(first);
    second = reverseLL(second);

    // Step 2 - add 2 LL
    Node *ans = add(first, second);

    return ans;
}

void print(Node *&n)
{
    while (n != NULL)
    {
        cout << n->data << "-> ";
        n = n->next;
    }
}

int main()
{
    Node *head1 = new Node(1);
    Node *second1 = new Node(2);
    Node *third1 = new Node(2);
    Node *fourth1 = new Node(0);
    Node *fifth1 = new Node(1);

    head1->next = second1;
    second1->next = third1;
    third1->next = fourth1;
    fourth1->next = fifth1;
    fifth1->next = NULL;

    Node *head2 = new Node(1);
    Node *second2 = new Node(2);
    Node *third2 = new Node(2);
    Node *fourth2 = new Node(0);
    Node *fifth2 = new Node(1);

    head2->next = second2;
    second2->next = third2;
    third2->next = fourth2;
    fourth2->next = fifth2;
    fifth2->next = NULL;

    Node*res = addTwoLists(head1,head2);
    print(res);

    return 0;
}