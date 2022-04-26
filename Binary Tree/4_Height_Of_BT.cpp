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

int height(Node *root)
{
    if(root == NULL)
    return 0;

    // max (Height of Left Subtree , Height of Right Subtree) + 1 [for root node]
    return max(height(root->left), height(root->right))+1;
}
signed main(){
    eff;
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    cout<<height(root);
    return 0;
}

// Time Complexity: O(n)
// Auxiliary Space: O(height of tree)

