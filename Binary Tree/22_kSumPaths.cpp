#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// we have to find longest branch sum
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

void solve(Node *root, int k, int &count, vector<int> path)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    path.push_back(root->data);
    // left
    solve(root->left, k, count, path);
    // right
    solve(root->right, k, count, path);

    // check for k sum
    int size = path.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
        {
            count++;
        }
    }
    path.pop_back();
}

int sumK(Node *root, int k)
{
    vector<int> path;
    int count = 0;
    solve(root, k, count, path);
    return count;
}

int main()
{
    Node *root = NULL;

    root = buildTree(root);
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1