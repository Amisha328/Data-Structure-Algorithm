// Deepest Leaves Sum
// Problem link:
// https://leetcode.com/problems/deepest-leaves-sum/
// https://leetcode.com/problems/deepest-leaves-sum/discuss/1152947/Deepest-Leaves-Sum-or-Short-and-Easy-Solutions-w-Explanation-or-BFS-and-DFS-Approach

#include<bits/stdc++.h>
using namespace std;

/*
Solution - I (DFS Traversal)

We maintain sum which will store sum of values of deepest level nodes till now and deepest which will store the depth or level of the deepest nodes. There will be following cases available to us where current Node is -

Not a Leaf Node - Traverse the left and right node of the current node.
A Leaf Node - This case will have 3 sub-cases possible -
depth > deepest - If current node is the deepest node observed till now, reset the sum to current node value and set deepest = depth.
depth == deepest - The current node is part of the deepest nodes observed till now. Add current root value to sum.
depth < deepest - This node is not the deepest node. Just ignore this node.
A NULL Node - We can't traverse any further. So just return.

*/

class Solution {
public:
    int deepest = 0, sum = 0;
    int findSum(TreeNode *root, int depth){
        if(root == NULL) return 0;
        if(!root -> left && !root -> right){
            if(depth == deepest) sum += root->val;
            else if(depth > deepest){
                deepest = depth;
                sum = root->val;
            }
        }
        findSum(root->left, depth+1) ;
        findSum(root->right, depth+1); 
        return sum;
    }
    int deepestLeavesSum(TreeNode* root) {
        return findSum(root, 0);
    }
};

