// Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/
// https://practice.geeksforgeeks.org/problems/preorder-traversal/1#


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

    // Recursive Solution
    // TC-> O(n) | SC-> O(height of the tree)
    
    vector<int> preorder;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return preorder;
        preorder.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return preorder;
    }

    /*
    // Iterative  Solution
    // TC-> O(n) | SC-> O(n)
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int> preorder;
         stack<TreeNode*> s;
        while(root != NULL || !s.empty())
        {
            while(root != NULL)
            {
                preorder.push_back(root->val);
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            root = root->right;
        }
        return preorder;
    }
    */

signed main(){
    eff;
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(40);
    root->right->right = new TreeNode(50);
    vector<int> preorder;
    preorder = preorderTraversal(root);
    for(auto x : preorder)
          cout<<x<<" ";
    return 0;
}