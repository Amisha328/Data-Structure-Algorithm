// Maximum Sum BST in Binary Tree
// problem link:
// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
// https://www.codingninjas.com/codestudio/problem-details/maximum-sum-bst-in-binary-tree_2099910



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
class NodeValue
{
    public: int maxSum, maxValue, minValue;
    public:
    NodeValue(int minValue, int maxValue, int maxSum)
    {
        this->minValue = minValue;
        this->maxValue = maxValue;
        this->maxSum = maxSum;
    }
};
int ans;
NodeValue largestBSTHelper(Node *root)
{
        // An empty tree is a BST of size 0.
        // maxValue to be the extream small
        // minValue to be the extream larger
        // To make it comparable
        if(!root)
            return NodeValue(INT_MAX, INT_MIN, 0);
        
        // Get values from left and right subtree of current tree.
        auto left = largestBSTHelper(root->left);
        auto right = largestBSTHelper(root->right);
        
        // Current node is greater than max value in left AND smaller than min value in right, it is a BST.
        if(left.maxValue < root->data && root->data < right.minValue)
        {
            ans = max(ans, left.maxSum + right.maxSum + root->data);
            return NodeValue(min(root->data, left.minValue), max(root->data, right.maxValue), left.maxSum + right.maxSum + root->data);
        }
        // Otherwise, return [-inf, inf] so that parent can't be valid BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSum, right.maxSum));
    }
int maximumSumBST(Node* root){
    // Write your code here
	ans = INT_MIN;
	largestBSTHelper(root);
    return ans > 0 ? ans : 0;
}
