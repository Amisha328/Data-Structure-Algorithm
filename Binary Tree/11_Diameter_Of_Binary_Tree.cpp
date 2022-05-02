// Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/
// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
// https://www.codingninjas.com/codestudio/problems/diameter-of-the-binary-tree_920552?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos

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
   // TC -> O(n) || SC-> O(Height of the Tree).
   int height(Node* root, int &diameter)
    {
        if(root == NULL) return 0;
        int lh = height(root->left, diameter);
        int rh = height(root->right, diameter);
        // if question says [Leetcode, CodeStudio]
        // The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
        // This path may or may not pass through the root.
        diameter = max(diameter, (lh+rh));
        // if question says [GFG]
        // The diameter of a tree is the number of nodes on the longest path between two end nodes.
        // diameter = max(diameter, (lh+rh+1));
        return 1+max(lh,rh);
    }
    
    int diameterOfBinaryTree(Node* root) 
    {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
    /*
    // naive solution: O(n^2)
    int height(Node *root)
    {
        if(root == NULL) return 0;
        else
        return 1+max(height(root->left),height(root->right));
    }
    int diameter(Node* root) 
        
        if(root == NULL) return 0;
        int d1 = 1+height(root->left)+height(root->right);
        int d2 = diameter(root->left);
        int d3 = diameter(root->right);
        
        return max(d1,max(d2,d3));
    }
   */
signed main(){
    eff;
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    cout<<diameterOfBinaryTree(root)<<endl;
    return 0;
}