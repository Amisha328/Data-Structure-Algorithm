// Count Leaf Nodes
// https://practice.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

struct Node
{
    int key;
    Node *left, *right;

    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

int countLeaves(Node *root)
{
    if(root == NULL)
    return 0;

    if(root->left == NULL && root->right == NULL)
          return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}
signed main(){
    eff;
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    cout<<countLeaves(root);
    return 0;
}

// Time Complexity: O(n)
// Auxiliary Space: O(height of tree)

