// Largest BST in Binary Tree
// Problem link:
// https://practice.geeksforgeeks.org/problems/largest-bst/1#
// https://www.codingninjas.com/codestudio/problem-details/largest-bst-subtree_893103


#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// TC-> O(N) | SC-> O(1) [ignoring the recursion call stack space]
class NodeValue
{
    public: int maxSize, maxValue, minValue;
    public:
    NodeValue(int minValue, int maxValue, int maxSize)
    {
        this->minValue = minValue;
        this->maxValue = maxValue;
        this->maxSize = maxSize;
    }
};
class Solution{
    private:
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
            return NodeValue(min(root->data, left.minValue), max(root->data, right.maxValue), left.maxSize + right.maxSize + 1);
        }
        // Otherwise, return [-inf, inf] so that parent can't be valid BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here
    	return largestBSTHelper(root).maxSize;
    }
};