// Insert into a Binary Search Tree
// Problem link:
// https://leetcode.com/problems/insert-into-a-binary-search-tree/
// https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1#

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

/*
// iterative solution
// TC->O(log2N)
Node* insertIntoBST(Node* root, int val) {
        if(!root) return new Node(val);
        Node *curr = root;
        while(true)
        {
            if(curr->data <= val)
            {
                if(curr->right != NULL)
                    curr = curr->right;
                else
                {
                     curr->right = new Node(val);
                        break;
                }
            }
            else
            {
                if(curr->left != NULL)
                    curr = curr->left;
                else
                {
                    curr->left = new Node(val);
                    break;
                }
            }
        }
        
        return root;
    }
    */
    
    // Recursive
    Node* insertIntoBST(Node* root, int val) {
        if(!root) return new Node(val);
        if(root->data <= val)
            root->right = insertIntoBST(root->right, val);
        else
            root->left = insertIntoBST(root->left, val);
        
        return root;
    }