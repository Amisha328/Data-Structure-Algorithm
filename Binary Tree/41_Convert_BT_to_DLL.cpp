// Convert A Given Binary Tree To Doubly Linked List
// Problem link:
// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1
// https://www.codingninjas.com/codestudio/problem-details/convert-a-given-binary-tree-to-doubly-linked-list_893106

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

// TC->O(n) | SC->O(H)
Node *prev = NULL;
Node * bToDLL(Node *root)
{
        
        // if root is NULL means no left or right subtree then return root
        if(root == NULL) return root;
        
        Node *head = bToDLL(root->left);
        
        if(prev == NULL)
          head = root;
        
        // we need to do the inorder traversal of the Tree and
        // while doing inorder traversal we can simply maintain a previous pointer
        // of the previously traversed node, 
        // and change right child of the previous node to current node and
        // left child of current node as previous.
        else
        {
            root->left = prev;
            prev->right = root;
        }
        
        prev = root;
        
        bToDLL(root->right);
        
        return head;
        
}