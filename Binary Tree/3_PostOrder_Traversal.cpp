// Postorder Traversal
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

    // Recursive solution
    // Time Complexity: O(n)
    // Auxiliary Space: O(height of tree)
    vector<int> postorder;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL)
            return postorder;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        postorder.push_back(root->val);
        return postorder;
       }

signed main(){
    eff;
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(40);
    root->right->right = new TreeNode(50);
    vector<int> postorder;
    postorder = postorderTraversal(root);
    for(auto x : postorder)
          cout<<x<<" ";
    return 0;
}