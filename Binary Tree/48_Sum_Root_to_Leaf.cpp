// Sum Root to Leaf Numbers
// Problem link: https://leetcode.com/problems/sum-root-to-leaf-numbers/

class Solution {
public:
    int dfs(TreeNode* root, int currNode){
        if(!root) return 0;
        currNode = currNode * 10 + root->val;
        if(!root->left && !root->right) return currNode;
        return dfs(root->left, currNode) + dfs(root->right, currNode);  
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};