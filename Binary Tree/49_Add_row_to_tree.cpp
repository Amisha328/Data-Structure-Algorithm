// Add One Row to Tree
// Problem link:
// https://leetcode.com/problems/add-one-row-to-tree/

// TC-> O(n) | SC-> O(n)

#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    void insert(TreeNode* node, int val, int depth, int level)
    {
        if(!node) return;
        if(level == depth-1)
        {
            TreeNode* temp = node->left;
            node->left = new TreeNode(val);
            node->left->left = temp;
            temp = node->right;
            node->right = new TreeNode(val);
            node->right->right = temp;
        }
        else
        {
            insert(node->left, val, depth, level+1);
            insert(node->right, val, depth, level+1);
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
        {
            TreeNode *newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        insert(root, val, depth, 1);
        return root;
    }
};