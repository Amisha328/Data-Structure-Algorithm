// Kth largest element in BST 
// Problem link:
// https://www.codingninjas.com/codestudio/problem-details/k-th-largest-number_920438
// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1/#

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

void inorder(Node* root, int &k, int &ans)
{
        if(root == NULL)
        return;
    
        inorder(root -> right, k, ans);
        
        k--;
        
        if(k == 0)
        {
            ans = root -> data;
            return ;
        }
        
        inorder(root -> left, k, ans);
}
int kthLargest(Node *root, int K)
{
        //Your code here
        int ans = 0;
        inorder(root, K, ans);
        return ans;
}