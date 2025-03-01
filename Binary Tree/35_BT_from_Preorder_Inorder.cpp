// Construct Binary Tree from Preorder and Inorder Traversal
// problem link:
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/


class Solution {
public:
    /*
    // TC -> O(n^2)
    int preIndex = 0;
    TreeNode* BT(vector<int>& preorder, vector<int>& inorder, int start, int end)
    {
        if(start > end) return NULL;
        TreeNode * root = new TreeNode(preorder[preIndex++]);
        
        int idx = 0;
        for(int i = start; i <= end; i++)
        {
            if(inorder[i] == root->val)
            {
                idx = i;
                break;
            }
        }
        
        root->left = BT(preorder, inorder, start, idx-1);
        root->right = BT(preorder, inorder, idx+1, end);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int s = 0;
        int e = inorder.size()-1;
        return BT(preorder, inorder, s, e);
    }
    */
    
    // TC->O(n)
    map<int, int> mp;
    TreeNode* BT(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd)
    {
        if(preStart > preEnd || inStart > inEnd) return NULL;
        TreeNode *node = new TreeNode(preorder[preStart]);
        int idx = mp[node->val];
        int leftNodes = idx - inStart;  // tell the number of values to the left of node at idx in inorder
        
        node->left = BT(preorder, preStart+1, preStart+leftNodes, inorder, inStart, idx-1);
        node->right = BT(preorder, preStart+leftNodes+1, preEnd, inorder, idx+1, inEnd);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        
        return BT(preorder, 0, preorder.size()-1, inorder, 0, inorder.size());
    }
};