#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    int data;
    cout << "Enter the data " << endl;
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for inserting in the left " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for inserting in the right " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

int maximumInBT(Node *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }

    int res = root->data;

    int left = maximumInBT(root->left);
    int right = maximumInBT(root->right);

    if (left > res)
    {
        res = left;
    }
    if (right > res)
    {
        res = right;
    }
    return res;
}

int main()
{
    Node *root = NULL;

    root = buildTree(root);
    cout<<"The maximum node in given Biary Tree is " << maximumInBT(root);

    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1