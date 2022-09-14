// Count number of nodes in a complete Binary Tree
// In a complete binary tree, and all nodes in the last level are as far left as possible. 
// It can have between 1 and 2h nodes inclusive at the last level h.
// problem link:
// https://leetcode.com/problems/count-complete-tree-nodes/

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

// TC-> O(log n)^2 | SC->O(log n)

// Formula is (2^TreeLevel - 1). Only works for perfect tree.
int countNodes(Node* root) 
{
        if(root == NULL)
            return 0;
        int lh = 0,rh = 0;
        Node *curr = root;
        // To determine if its a perfect tree, go all the way down and count the nodes on left and right side.
        // O(log n) -> to find the lh and rh
        while(curr != NULL)
        {
            lh++;
            curr = curr->left;
        }
        curr = root;
        while(curr != NULL)
        {
            rh++;
            curr = curr->right;
        }
        // If they match, its a perfect tree and our formula applies.
        if(lh == rh)
            return  (1 << lh) - 1;  // 1 << n is same as 2^n 
        // If its not a perfect tree, we go on left and right subtree and again determine if they are perfect tree.
        else
            return 1 + countNodes(root->left)+countNodes(root->right);  // O(log n) 
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
    cout<<countNodes(root);
    return 0;
}