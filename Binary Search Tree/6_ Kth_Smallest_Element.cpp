//  Kth Smallest Element in a BST
// problem link:
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1/#


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

// TC->O(K) || SC-> O(1) [ not considering the recursion call stack]
void inorder(Node* root, int &k, int &ans)
{
        if(root == NULL)
        return;
    
        inorder(root -> left, k, ans);
        
        k--;
        
        if(k == 0)
        {
            ans = root -> data;
            return ;
        }
        
        inorder(root -> right, k, ans);
}
int KthSmallestElement(Node *root, int K) 
{
        int ans = -1;
        inorder(root, K, ans);
        return ans;
}