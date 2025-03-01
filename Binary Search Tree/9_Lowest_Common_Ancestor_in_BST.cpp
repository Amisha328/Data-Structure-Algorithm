// Lowest Common Ancestor in a BST
// Problem link:
// https://www.codingninjas.com/codestudio/problem-details/lca-in-a-bst_981280
// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/

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

Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   if(!root) return NULL;
   int curr = root->data;
   // both lies on the right
   if(curr < n1 && curr < n2)
    return LCA(root->right, n1, n2);
   // both lies on the left
   if(curr > n1 && curr > n2)
    return LCA(root->left, n1, n2);
   // else one is on the left and other on the right, so the split point(node) is LCA
   return root;
}