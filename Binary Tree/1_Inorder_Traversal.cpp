// Inorder taversal
// Problem links:
// https://leetcode.com/problems/binary-tree-inorder-traversal/
// https://practice.geeksforgeeks.org/problems/inorder-traversal/1#


#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

struct TreeNode
{
    int val;
   TreeNode *left, *right;

    TreeNode(int k)
    {
        val = k;
        left = right = NULL;
    }
};

    // Recursive solution
    // Time Complexity: O(n)
    // Auxiliary Space: O(height of tree)
    /*
    vector<int> inorder;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL)
            return inorder;
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);  
        return inorder;
    }
    */
    // Iterative solution
    // Time Complexity: O(n) : as pushing and poping to a stack requires O(1) time.
    // Auxiliary Space: O(n)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> s;
        while(root != NULL || !s.empty())
        {
            while(root != NULL)
            {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            inorder.push_back(root->val);
            root = root->right;
        }
        return inorder;
    }

signed main(){
    eff;
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(40);
    root->right->right = new TreeNode(50);
    vector<int> inorder;
    inorder = inorderTraversal(root);
    for(auto x : inorder)
          cout<<x<<" ";
    return 0;
}