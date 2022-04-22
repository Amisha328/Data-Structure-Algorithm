// Search in Binary Search Tree
// The basic idea is that we end up with a leaf note if the key is not present in the BST.
// Problem link:
// https://leetcode.com/problems/search-in-a-binary-search-tree/submissions/
// https://practice.geeksforgeeks.org/problems/search-a-node-in-bst/1#


#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>


struct Node
{
    int key;
    struct Node *left, *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

// Recursive
/*
bool rec_search(Node *root, int data)
{
    if (root == NULL) return false;
    if (root->key == data) return true;
    if (root->key > data) return search(root->left, data);
    else return search(root->right, data);
}
*/

// iterative
bool ite_search(Node *root, int data)
{
    while(root != NULL)
    {
        if(root->key == data)
            return true;
        else if(root->key > data)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}
signed main(){
    eff;
    Node *root = new Node(15);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->right->left = new Node(18);
    root->right->right = new Node(20);
    root->right->left->left = new Node(16);

    int data = 16;
    // cout<<rec_search(root, data);
    //cout<<endl;
    cout<<ite_search(root, data);
    return 0;
}

// Time Complexity: O(log2N) = height of tree
// Auxiliary Space for iterative: O(h)
// Auxiliary space for recursive: O(1)