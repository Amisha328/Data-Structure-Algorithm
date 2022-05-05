// Binary Tree Maximum Path Sum from any node to any node
// https://leetcode.com/problems/binary-tree-maximum-path-sum/
// https://www.codingninjas.com/codestudio/problem-details/binary-tree-maximum-path-sum_1280142

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

int pathSum(Node* root, int &res)
{
        if(root == NULL) return 0;
        // if leftSum [all its child have -ve val] return a negative value then 0 is to be taken
        int leftSum = max(0, pathSum(root->left, res));
         // if rightSum return a negative value then 0 is to be taken
        int rightSum = max(0, pathSum(root->right, res));
        res = max(res, (leftSum + rightSum + root->data));
        return (root->data + max(leftSum, rightSum));
}
int maxPathSum(Node* root) 
{
        // if -3 is the only node then -3 is the maxPathSum and not 0 
        // so we will initialize res as INT_MIN and not 0
        int res = INT_MIN;
        pathSum(root, res);
        return res;
}

signed main(){
    eff;
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    cout<<maxPathSum(root);
    return 0;
}
