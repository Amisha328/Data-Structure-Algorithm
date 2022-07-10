// Ceil from BST
// problem link:
// https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=0

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

int findCeil(Node *node, int x)
{
    int ceil = -1;
    while(node)
    {
        if(node->data == x)
        {
            ceil = node->data;
            return ceil;
        }
        else if(node->data < x)
            node = node->right;
        else
        {
            ceil = node->data;
            node = node->left;
        }
    }
    return ceil;
}