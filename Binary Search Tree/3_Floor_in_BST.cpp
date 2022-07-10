// Floor in Binary Search Tree
// Problem link:
// https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=0


#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    struct Node *left, *right;
    Node(int k)
    {
        val = k;
        left = right = NULL;
    }
};

// TC->O(log2N)
int floorInBST(Node* root, int X)
{
    int floor = -1;
    while(root)
    {
        if(root->val == X)
        {
            floor = root->val;
            return floor;
        }
        else if(root->val < X)
        {
            floor = root->val;
            root = root->right;
        }
        else
            root = root->left;
    }
    return floor;
}
