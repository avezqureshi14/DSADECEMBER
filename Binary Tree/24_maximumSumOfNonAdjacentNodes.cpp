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

pair<int,int>solve(Node*root){
     //base case
     if (root == NULL)
     {
        pair<int,int> p = make_pair(0,0);
        return p;
     }

     pair<int,int> left = solve(root->left);
     pair<int,int> right = solve(root->right);

     pair<int,int>res;

     res.first = root->data + left.second + right.second;
     res.second = max(left.first,left.second) + max(right.first,right.second);
     
     return res;
}

int getMaxSum(Node*root){
    pair<int,int>ans = solve(root);
    // ans.first = maximum sum including nodes in current level
    // ans.second = maximum sum excluding nodes in current level
    return max(ans.first, ans.second);
}


int main()
{
    Node *root = NULL;

    root = buildTree(root);
    cout<<"Maximum sum of non adjacent nodes is "<<getMaxSum(root);
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1