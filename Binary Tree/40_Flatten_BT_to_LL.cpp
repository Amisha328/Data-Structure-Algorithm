// Flatten binary tree to linked list 
// Problem link:
// https://www.codingninjas.com/codestudio/problem-details/flatten-binary-tree-to-linked-list_1112615
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/0/#

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

class Solution {
public:
    // Approch 1: Recursive
    // TC->O(n) | SC->O(n)
    /*
    Node *prev = NULL;
    void flatten(Node* root) {
        if(!root) return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right = prev;
        root->left = NULL;
        
        prev = root;
    }
    */
    
    // Approach 2: using Stack
    // TC->O(n) | SC->O(n)
    /*
    void flatten(Node* root) {
        if(root == NULL) return;
        stack<Node*> st;
        st.push(root);
        while(!st.empty())
        {
             Node *curr = st.top();
             st.pop();
            
            if(curr->right)
                st.push(curr->right);
            if(curr->left)
                st.push(curr->left);
            
            if(!st.empty())
                curr->right = st.top();
            
            curr->left = NULL;
        }
    }
    */
    
    // Morris Traversal
    // TC->O(n) | SC->O(1)
    void flatten(Node* root) {
        if(!root) return;
        Node *curr = root;
        while(curr)
        {
            if(curr->left != NULL)
            {
                Node *prev = curr->left;
            
                while(prev->right)
                    prev = prev->right;

                prev->right = curr->right;
                curr->right = curr->left;
            }
            curr->left = NULL;
            curr = curr->right;
        }
    }
};