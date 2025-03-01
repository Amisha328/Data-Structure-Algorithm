// Lowest Common Ancestor
// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1#
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/


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
Node* lca(Node* root ,int n1 ,int n2 )
{
        if(root == NULL) return NULL;
        
        if(root->data == n1 || root->data == n2)
            return root;
        
        Node *ls = lca(root->left, n1, n2);
        Node *rs = lca(root->right, n1, n2);
        
        // if one key is in left subtree and other in right subtree
        if(ls && rs)
            return root;
        
        // Both keys in left subtree
        if(ls)
            return ls;

          // both keys in right subtree
        else
            return rs;
}
signed main(){
    eff;
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
    Node *node = lca(root, 20, 70);
    cout<<node->data;
    return 0;
}