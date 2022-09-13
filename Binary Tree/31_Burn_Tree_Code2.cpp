// Minimum time taken to BURN the Binary Tree from a Node or Leaf
// Problem link:
// https://www.codingninjas.com/codestudio/problem-details/time-to-burn-tree_630563
// https://practice.geeksforgeeks.org/problems/burning-tree/1/?category#

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
int maxDepth(Node* root)
{
          if(root==NULL)return 0;
          return 1 + max(maxDepth(root->left),maxDepth(root->right));
}
      
int burning(Node* root,int tar,int &res)
{
          if(root==NULL)return 0;
          
          if(root->data==tar)
          {
               res = max(res, maxDepth(root)-1);
                return 1;
          }
          
          int ans = burning(root->left,tar,res);
          if(ans)
          {
              res = max(res, ans+ maxDepth(root->right));
              return ans+1;
          }
          
           ans = burning(root->right,tar,res);
          if(ans)
          {
              res = max(res, ans+ maxDepth(root->left));
              return ans+1;
          }
          return 0;
}
int minTime(Node* root, int target) 
{
        int res=0;
        burning(root,target,res);
        return res;
        
}
signed main(){
    eff;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->right = new Node(7);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    int start = 2;
    cout<<minTime(root, start);
    return 0;
}