// Balance a Binary Search Tree
// Problem link:
// https://leetcode.com/problems/balance-a-binary-search-tree/
// https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1/

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
void findInorder(Node *root, vector<int> &inorder){
        if(!root) return;
        findInorder(root->left, inorder);
        inorder.push_back(root->data);
        findInorder(root->right, inorder);
}
Node* inorderToBST(vector<int> &arr, int start, int end)
{
        if(start > end) return NULL;

        int mid = (start + end) >> 1;
        Node *root = new Node(arr[mid]);
        root->left = inorderToBST(arr, start, mid-1);
        root->right = inorderToBST(arr, mid+1, end);

        return root;
}
Node* balanceBST(Node* root) {
        vector<int> inorder;
        findInorder(root, inorder);
        return inorderToBST(inorder, 0, inorder.size()-1);
}