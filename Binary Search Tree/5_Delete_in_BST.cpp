// Delete a node from BST
// Problem link:
// https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1/#
// https://leetcode.com/problems/delete-node-in-a-bst/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
          int data;
          Node *left, *right;
          Node(int k)
          {
                    data = k;
                    left = right = NULL;
          }
};

// TC->O(Height of the tree)
Node *findLastRight(Node *root)
{
    if(root->right == NULL)
        return root;
    return findLastRight(root->right);
}
Node *helper(Node *root)
{
    if(root->left == NULL)
        return root->right;
    else if(root->right == NULL)
        return root->left;
        
    Node *rightChild = root->right;
    Node *lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}
Node *deleteNode(Node *root, int X) {
    // your code goes here
    if(root == NULL) return NULL;
    if(root->data == X)
        return helper(root);
        
    Node *temp = root;
    while(root)
    {
        if(root->data > X)
        {
            if(root->left != NULL && root->left->data == X)
            {
                root->left = helper(root->left);
                break;
            }
            else
                root = root->left;
        }
        else
        {
            if(root->right != NULL && root->right->data == X)
            {
                root->right = helper(root->right);
                break;
            }
            else
                root = root->right;
    
        }
    }
        return temp;
}
