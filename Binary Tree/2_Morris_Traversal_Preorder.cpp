// Morris Traversal Preorder Traversal
// Problem link:
// https://leetcode.com/problems/binary-tree-preorder-traversal/submissions/

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

// TC->O(N) | SC->O(1)
vector<int> preorderTraversal(Node* root) {
        vector<int> preorder;
        if(!root) return preorder;
        Node *curr = root;
        
        while(curr)
        {
            // case 1: if left is NULL, print current root, move right
            if(curr->left == NULL)
            {
                preorder.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                // case 2: before going left, make right most node on left subtree connected to current node, then go left
                Node *prev = curr->left;
                while(prev->right && prev->right != curr)
                {
                    prev = prev->right;
                }
                if(prev->right == NULL)
                {
                    prev->right = curr;
                    preorder.push_back(curr->data);
                    curr = curr->left;
                }
                else
                {
                    // case 3: if thread is already pointed to current node, then remove the thread and move right
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return preorder;
}