// Range Sum of BST
// Problem link: https://leetcode.com/problems/range-sum-of-bst/

#include <bits/stdc++.h>
class Solution {
public:
    int getSum(TreeNode* root, int low, int high)
    {
        if (!root) return 0;
 
        // Special Optional case for improving efficiency
        if (root->val == high && root->val == low)
            return root->val;

        // If current node is in range, then include it in count and
        // recur for left and right children of it
        if (root->val <= high && root->val >= low)
             return root->val + getSum(root->left, low, high) +
                        getSum(root->right, low, high);

        // If current node is smaller than low, then recur for right
        // child
        else if (root->val < low)
             return getSum(root->right, low, high);

        // Else recur for left child
        else return getSum(root->left, low, high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return getSum(root, low, high);
    }
};