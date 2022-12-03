#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
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
    cout << "Enter the data" << endl;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);

    cout << "Enter the data to the left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data to the right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

bool isIdentical(Node *r1, Node *r2)
{

    if (r1 == NULL && r2 != NULL)
    {
        return false;
    }

    if (r1 != NULL && r2 == NULL)
    {
        return false;
    }

    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }

    bool left = isIdentical(r1->left,r2->left);
    bool right = isIdentical(r1->right,r2->right);
    bool value = r1->data == r2 ->data;

    if (left && right && value)
    {
        return true;
    }
    else{
        return false;
    }
    
    
}

int main()
{
    Node *r1 = NULL;
    r1 = buildTree(r1);
    Node *r2 = NULL;
    r2 = buildTree(r2);

    if (isIdentical(r1,r2))
    {
        cout<<"Identical";
    }
    else{
        cout<<"UnIdentical";
    }
    
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1