// Construct Binary Search Tree from Preorder Traversal
// Problem link:
// https://www.codingninjas.com/codestudio/problems/preorder-traversal-to-bst_893111?leftPanelTab=0
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

#include<bits/stdc++.h>
using namespace std;


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

// TC -> o(N) | SC->O(1)
// here idx is passed by reference because it is changing ever time
Node *formPreOrder(vector<int> &pre, int &idx, int bound)
{
        if(idx == pre.size() || pre[idx] > bound) return NULL;
        Node *root = new Node(pre[idx++]);
        // if going left upper bound become the node value
        root->left = formPreOrder(pre, idx, root->data);
        // if going to right the same upper bound is transferred
        root->right = formPreOrder(pre, idx, bound);
        return root;
}
Node* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return formPreOrder(preorder, idx, INT_MAX);
}