// Longest path to the bottom of a Binary Tree forming an Arithmetic Progression
/*
Given a Binary Tree consisting of N nodes, the task is to find the length of the longest path
from any node to the bottom of the tree such that all the node values form an Arithmetic Progression.
*/

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
// TC-> O(N) | SC-> O(1)
void traversal(Node *root, int commonDiff, int count, int &maxLen)
{
          if(root->left)
          {
                    int diff = root->left->data - root->data;
                    if(diff == commonDiff)
                    {
                              traversal(root->left, commonDiff, count+1, maxLen);
                              maxLen = max(maxLen, count+1);
                    }
                    else
                              traversal(root->left, diff, 2, maxLen);
          }
          if(root->right)
          {
                    int diff = root->right->data - root->data;
                    if(diff == commonDiff)
                    {
                              traversal(root->right, commonDiff, count+1, maxLen);
                              maxLen = max(maxLen, count+1);
                    }
                    else
                              traversal(root->right, diff, 2, maxLen);
          }
}

int maxLengthOfAP(Node *root)
{
          if(!root) return 0;
          if(!root->left && !root->right) return 1;
          int maxLength = 2;
          if(root->left)
          {
                    int diff = root->left->data - root->data;
                    traversal(root->left, diff, 2, maxLength);
          }
          if(root->right)
          {
                  int diff = root->right->data - root->data;
                  traversal(root->right, diff, 2, maxLength);  
          }
          return maxLength;
}
int main()
{
          Node* root = new Node(6);
          root->right = new Node(9);
          root->right->left = new Node(7);
          root->right->right = new Node(12);
          root->right->right->right = new Node(15);
          cout<<maxLengthOfAP(root);
}