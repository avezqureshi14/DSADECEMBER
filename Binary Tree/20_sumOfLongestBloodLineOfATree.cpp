#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//we have to find longest branch sum
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

void solve(Node *root, int sum, int &maxSum, int len, int &maxlen)
{
    // base case
    if (root == NULL)
    {
        if (len > maxlen)
        {
            maxlen = len;
            maxSum = sum;
        }
        else if (len == maxlen)
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }
    sum = sum + root->data;

    solve(root->left,sum,maxSum,len+1,maxlen);
    solve(root->right,sum,maxSum,len+1,maxlen);
}

int sumOfLongRootToLeafPath(Node *root)
{
    int len = 0;
    int maxlen = 0;
    int sum = 0;
    int maxSum = INT_MIN;

    solve(root, sum, maxSum, len, maxlen);

    return maxSum;
}

int main()
{
    Node *root = NULL;

    root = buildTree(root);
    cout<<"Sum of Longest bloodline of a Tree is "<<sumOfLongRootToLeafPath(root);
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1