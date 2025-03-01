// Maximum difference between node and its ancestor
// Problem link:
// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/
// https://practice.geeksforgeeks.org/problems/maximum-difference-between-node-and-its-ancestor/1?
/*
You are given a task of finding the maximum value val, in a binary tree for which there exist different nodes a and b ; where val = |a.val - b.val| and a is an ancestor of b.
A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an predecessor of b.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

//Function to return the maximum difference between any node and its ancestor.
void solve(int preVal, Node *node, int &res){
    if(node == NULL) return;
    res = max(res, preVal-(node->data)); // getting the max differnece
    preVal = max(preVal, node->data); // get the large value to ancestor
    solve(preVal, node->left, res);
    solve(preVal, node->right, res);
}

int maxDiff(Node* root)
{
    int res = INT_MIN;
    
    solve(root->data, root->left, res);
    solve(root->data, root->right, res);
    
    return res;
}
