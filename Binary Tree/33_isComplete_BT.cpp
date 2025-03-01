// Check whether the given Binary Tree is Complete Binary Tree or not. 
// A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled,
// and all nodes are as far left as possible.
// Problem link:
// https://practice.geeksforgeeks.org/problems/complete-binary-tree/1#
// https://leetcode.com/problems/check-completeness-of-a-binary-tree/submissions/

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>


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
 bool isCompleteBT(Node* root)
 {
        if(!root) return true;
        // Intution : 
        // In a complete binary tree you will never encounter null node between the not nodes.
        queue<Node*> q;
        q.push(root);
        bool foundNull = false;
        while(!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            if(curr->left)
            {
                if(foundNull)
                    return false;
                q.push(curr->left);
            }
            else
                foundNull = true;
            if(curr->right)
            {
                if(foundNull)
                    return false;
                q.push(curr->right);
            }
            else
                foundNull = true;
        }
        return true;
}
signed main()
{
    eff;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    if(isCompleteBT)
          cout<<"Complete Binary Tree";
    else
          cout<<"Not Complete Binary Tree";
    return 0;
}