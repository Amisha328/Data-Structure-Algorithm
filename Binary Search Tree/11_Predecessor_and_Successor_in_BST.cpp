// Predecessor And Successor In BST
// Problem link:
// https://www.codingninjas.com/codestudio/problems/_893049?topList=top-fintech-software-engineer-interview-questions&leftPanelTab=0
// https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1/#

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

// TC->O(Height of Tree) | SC-> O(1)
pair<int,int> predecessorSuccessor(Node* root, int key)
{
    int pre = -1, suc = -1;
    Node* curr = root;
    while(curr)
    {
            if(curr->data >= key)
                curr = curr->left;
            else
            {
                pre = curr->data;
                curr = curr->right;
            }         
    } 
    curr = root;
    while(curr)
    {
            if(curr->data <= key)
                curr = curr->right;
            else
            {
                suc = curr->data;
                curr = curr->left;
            }
    }
    return {pre, suc};
}
