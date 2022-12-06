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

pair<bool, int> sumTreeMain(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = sumTreeMain(root->left);
    pair<bool, int> rightAns = sumTreeMain(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;

    bool condition = root->data == leftAns.second + rightAns.second;

    pair<bool, int> ans;

    if (left && right && condition)
    {
        ans.first = true;
        ans.second = root->data;
    }
    else
    {
        ans.first = false;
        ans.second = root->data;
    }

    return ans;
}

bool sumTree(Node *root)
{
    return sumTreeMain(root).first;
}

Node *createBT(Node *root)
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
    root->left = createBT(root->left);
    cout << "Enter the data to the right of " << data << endl;
    root->right = createBT(root->right);

    return root;
}

int main()
{
    Node *root = NULL;
    root = createBT(root);
    if (sumTree(root))
    {
        cout << "Yeah! It is Sum Tree";
    }
    else
    {
        cout << "Nope";
    }

    return 0;
}