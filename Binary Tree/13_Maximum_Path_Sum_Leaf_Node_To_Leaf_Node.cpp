// Maximum Path Sum between two Leaf Nodes.
// Here Leaf node is a node which is connected to exactly one different node.
// https://practice.geeksforgeeks.org/problems/maximum-path-sum/1#

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

int maxSum(Node *node, int &sum)
{
        if(node == NULL) return 0;
        int leftSum = maxSum(node->left, sum);
        int rightSum = maxSum(node->right, sum);
        if(!node->left && !node->right)
            return node->data;
        if(!node->left)
            return node->data + rightSum;
        if(!node->right)
            return node->data + leftSum;
        sum = max(sum, leftSum + rightSum + node->data);
        return (node->data + max(leftSum, rightSum));
}
int maxPathSum(Node* root)
{
        // code here
        int sum = INT_MIN;
        int ans = maxSum(root, sum);
        // Here Leaf node is a node which is connected to exactly one different node.
        // If root has only one child the it is also a leaf node
        // hence, will be counted
        if(!root->left || !root->right)
            sum = max(sum, ans);
        return sum;
}

signed main(){
    eff;
    Node *root = new Node(5);
    root->right = new Node(6);
    root->right->left = new Node(-5);
    root->right->right = new Node(5);

    cout<<maxPathSum(root);
    return 0;
}