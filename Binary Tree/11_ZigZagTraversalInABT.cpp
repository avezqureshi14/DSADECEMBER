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

vector<vector<int>> zigZagTraversal(Node *root)
{
    vector<vector<int>> result;
    if (root == NULL)
    {
        return result;
    }

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        bool leftToright = true;
        for (int i = 0; i < size; i++)
        {
            Node *frontNode = q.front();
            q.pop();
            int index = leftToright ? i : size - i - 1;
            ans[index] = frontNode->data;

            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }

        leftToright = !leftToright;
        result.push_back(ans);
    }

    return result;
}

int main()
{
    Node *root = NULL;

    root = buildTree(root);

    for (auto i : zigZagTraversal(root))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
    }

    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1