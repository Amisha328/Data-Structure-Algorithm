// Bottom-up level order traversal 
// Problem link: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> bottomUp;
        if(!root) return bottomUp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> levels;
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode *curr = q.front();
                q.pop();
                levels.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            bottomUp.push_back(levels);
        }
        reverse(bottomUp.begin(), bottomUp.end());
        return bottomUp;
    }
};