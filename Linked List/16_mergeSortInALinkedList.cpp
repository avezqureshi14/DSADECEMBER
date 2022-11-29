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

Node *findMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge(Node *left, Node *right)
{

    if (left == NULL)
        return right;

    if (right == NULL)
        return left;

    Node *ans = new Node(-1);
    Node *temp = ans;

    // merge 2 sorted Linked List
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;
    return ans;
}

Node *mergeSort(Node *head)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // break linked list into 2 halvs, after finding mid
    Node *mid = findMid(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    // recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // merge both left and right halves
    Node *result = merge(left, right);

    return result;
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
    Node *second1 = new Node(12);
    Node *third1 = new Node(2);
    Node *fourth1 = new Node(10);
    Node *fifth1 = new Node(19);

    head1->next = second1;
    second1->next = third1;
    third1->next = fourth1;
    fourth1->next = fifth1;
    fifth1->next = NULL;

    Node*res = mergeSort(head1);
    print(res);
    return 0;
}