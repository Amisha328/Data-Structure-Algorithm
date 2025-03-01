// Increasing Order Search Tree
// problem link: 
// https://leetcode.com/problems/increasing-order-search-tree/
// https://www.codingninjas.com/codestudio/problem-details/increasing-order-search-tree_1230783

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
    void inorder(Node *root, Node *&temp)
    {
        if(!root) return;
        inorder(root->left, temp);
        temp->right = new Node(root->data);
        temp->left = NULL;
        temp = temp->right;
        inorder(root->right, temp);
    }
    Node* increasingBST(Node* root) {
        Node *dummy = new Node(0);
        Node *temp = dummy;
        inorder(root, temp);
        return dummy->right;
    }