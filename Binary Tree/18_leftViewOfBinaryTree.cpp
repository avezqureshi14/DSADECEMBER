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

void solve(Node*root, vector<int> &ans, int level){
    //base case
    if (root == NULL)
    {
        return;
    }

    //we eneterd into a new level
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    solve(root->left, ans, level +1);
    solve(root->right, ans, level +1);
    
    
}

vector<int>leftView(Node*root){
    vector<int>ans;
    solve(root,ans,0);
    return ans;
}

int main()
{
    Node *root = NULL;

    root = buildTree(root);

    vector<int> res;
    res = leftView(root);
    for (auto i : res)
    {
        cout << i << " ";
    }
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1