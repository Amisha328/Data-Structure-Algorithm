// Symmetric Tree
// https://leetcode.com/problems/symmetric-tree/
// https://practice.geeksforgeeks.org/problems/symmetric-tree/1#

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
bool check( struct Node* leftSubtree, struct Node* rightSubtree)
{
        if(!leftSubtree || !rightSubtree)
            return (leftSubtree == rightSubtree);
        if(leftSubtree->data != rightSubtree->data)
            return false;
        return (check(leftSubtree->left, rightSubtree->right) && check(leftSubtree->right, rightSubtree->left));
}
bool isSymmetric(struct Node* root)
{
	return (root == NULL || check(root->left, root->right));
}
signed main(){
    eff;
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(20);
    root->left->left = new Node(30);
    root->left->right = new Node(40);
    root->right->left = new Node(40);
    root->right->right = new Node(30);
    if(isSymmetric(root))
          cout<<"Symmetric"<<endl;
    else
          cout<<"Not Symmetric"<<endl;
    return 0;
}