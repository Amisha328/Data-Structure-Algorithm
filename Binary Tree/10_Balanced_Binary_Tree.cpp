// Check for Balanced Binary Tree 
// a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
// Problem link:
// https://leetcode.com/problems/balanced-binary-tree/
// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1#
// https://www.codingninjas.com/codestudio/problem-details/is-height-balanced-binary-tree_975497

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
int checkBalanced(Node *root)
{
        if(root == NULL)
        return 0;
        int lh = checkBalanced(root->left);
        if(lh == -1) return -1;
        int rh = checkBalanced(root->right);
        if(rh == -1) return -1;
        
        if(abs(lh-rh) > 1) return -1;
        else
            return max(lh,rh)+1;
}
bool isBalanced(Node *root)
{
        return (checkBalanced(root) != -1);
}

signed main(){
    eff;
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    cout<<isBalanced(root)<<endl;
    return 0;
}