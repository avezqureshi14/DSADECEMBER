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

void traverseLeft(Node *root, vector<int> &ans)
{
    // base case
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    ans.push_back(root->data);
    if (root->left)
    {
        traverseLeft(root->left,ans);
    }
    else
    {
        traverseLeft(root->right,ans);
    }
}

void traverseLeaf(Node*root,vector<int> &ans){
    // base case 
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
    
}

void traverseRight(Node*root,vector<int>&ans){
    //base case
    // base case
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    if (root->right)
    {
        traverseRight(root->right,ans);
    }
    else{
        traverseRight(root->right,ans);
    }
    
    ans.push_back(root->data);
}

vector<int>boundary(Node*root){
    vector<int>ans;
    if (root == NULL)
    {
        return ans;
    }

    ans.push_back(root->data);

    //left part print/store
    traverseLeft(root->left,ans);

    //traverse leaf nodes

    //left subtree
    traverseLeaf(root->left,ans);

    //right subtree
    traverseLeaf(root->right,ans);

    //right part print/store
    traverseRight(root->right,ans);

    return ans;
    
}


int main()
{
    Node *root = NULL;

    root = buildTree(root);
    vector<int> res = boundary(root);
    for(auto i : res){
        cout<<i<<" ";
    }
    
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1