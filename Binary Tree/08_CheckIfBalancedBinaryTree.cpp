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

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = left + right + 1;
    return ans;
}

bool isBalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right) <= 1);

    if (left && right && diff)
    {
        return true;
    }
    else
    {
        return false;
    }
}

pair<bool, int> optIsBalancedFirst(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = optIsBalancedFirst(root->left);
    pair<bool, int> right = optIsBalancedFirst(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = left.second - right.second <= 1;

    pair<bool, int> ans;
    ans.second = left.second + right.second + 1;

    if (leftAns && rightAns && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }

    return ans;
}

bool optIsBalanced(Node *root)
{
    return optIsBalancedFirst(root).first;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    if (optIsBalanced(root))
    {
        cout << "Balanced";
    }
    else
    {
        cout << "UnBalanced";
    }

    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1