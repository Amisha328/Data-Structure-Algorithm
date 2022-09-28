// Check BST
// Problem link:
// https://leetcode.com/problems/validate-binary-search-tree/
// https://practice.geeksforgeeks.org/problems/check-for-bst/1

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

// Approach 1: MIN-MAX Range
// Every node lies in a range:
// 1) Root lies between INT_MIN to INT_MAX
// 2) Left node lies in the range of INT_MIN and it's parent node value.
// 3) Right node lies in the range of it's parent node value and INT_MAX.

bool isValidBST(Node *root, int min, int max)
{
        if(!root) return true;
        if(root->data <= min || root->data >= max) return false;
        return (isValidBST(root->left, min, root->data) && isValidBST(root->right, root->data, max));
}
bool isBST(Node* root) {
        return isValidBST(root, INT_MIN, INT_MAX);
}

// Approach 2: Inorder Traversal of BST is always sorted

Node *prev = NULL;
bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(!isValidBST(root->left)) return false;
        if(prev != NULL && root->data <= prev->data) return false;
        prev = root;
        return isValidBST(root->right);
}
