// Recover Binary Search Tree
// Problem link: 
// https://leetcode.com/problems/recover-binary-search-tree/
// https://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1/#
// https://www.codingninjas.com/codestudio/problem-details/fix-bst_873137


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
// TC-> O(N) | SC->O(N) [recursion call stack]
class Solution 
{
    Node *prev;
    Node *first;
    Node *middle;
    Node *last;
public:
    void inorder(Node *root)
    {
        if(!root) return;
        inorder(root->left);
        // if prev value in inorder traversal is greater than the current value 
        // voilation is found
        if(prev != NULL && root->data < prev->data)
        {
            // if it's the first voilation encountered
            if(!first)
            {
                first = prev;
                middle = root;
            }
            else
                last = root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(Node* root) {
        first = middle = last = NULL;
        prev = new Node(INT_MIN);
        if(!root) return;
        inorder(root);
        // if first and last not null then nodes where voilation is encountered is not adjacent
        if(first && last) 
            swap(first->data, last->data);
        // if last is null then nodes where voilation is encountered is adjacent.
        // so swap the first and middle which stores the prev in middle and current in first
        else if(first && middle) 
            swap(first->data, middle->data);
    }
};
// Note: It's space complexity can be reduced to O(1) using Morris Traversal.