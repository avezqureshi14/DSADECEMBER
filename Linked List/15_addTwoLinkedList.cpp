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

Node *reverse(Node *head)
{

    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void insertAtTail(struct Node *&head, struct Node *&tail, int val)
{

    Node *temp = new Node(val);
    // empty list
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

    while (first != NULL || second != NULL || carry != 0)
    {

        int val1 = 0;
        if (first != NULL)
            val1 = first->data;

        int val2 = 0;
        if (second != NULL)
            val2 = second->data;

        int sum = carry + val1 + val2;

        int digit = sum % 10;

        // create node and add in answer Linked List
        insertAtTail(ansHead, ansTail, digit);

        carry = sum / 10;
        if (first != NULL)
            first = first->next;

        if (second != NULL)
            second = second->next;
    }
    return ansHead;
}

Node *addTwoLists(Node *first, Node *second)
{

    // step 1 -  reverse input LL
    first = reverse(first);
    second = reverse(second);

    // step2 - add 2 LL
    Node *ans = add(first, second);

    // step 3
    ans = reverse(ans);

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

    Node *res = addTwoLists(head1, head2);
    print(res);

    return 0;
}