// Construct Binary Tree from Inorder and Postorder Traversal
// Problem Link:
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/submissions/
// https://www.codingninjas.com/codestudio/problem-details/construct-binary-tree-from-inorder-and-postorder-traversal_1266106
// https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1/#

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

class Solution {
public:
    map<int, int> mp;
    Node* BT(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd)
    {
        if(inStart > inEnd || postStart > postEnd) return NULL;
        Node *root = new Node(postorder[postEnd]);
        int idx = mp[root->data];
        int leftNodes = idx - inStart;
        
        root->left = BT(inorder, inStart, idx-1, postorder, postStart, postStart+leftNodes-1);
        root->right = BT(inorder, idx+1, inEnd, postorder, postStart+leftNodes, postEnd-1);
        
        return root;
    }
    Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        
        return BT(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
