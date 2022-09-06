// Check whether all of its nodes have the value equal to the sum of their child nodes.
// Problem link: 
// https://practice.geeksforgeeks.org/problems/children-sum-parent/1#

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

// TC-> O(n) | SC->O(n)
int isSumProperty(Node *root)
{
         if(!root) return 1;
         if(!root->left && !root->right) return 1;
         int sum = 0;
         if(root->left)
            sum += root->left->data;
         if(root->right)
            sum += root->right->data;
            
        return (sum == root->data && isSumProperty(root->left) && isSumProperty(root->right));
}

signed main(){
    eff;
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(5);
    if(isSumProperty(root))
          cout<<"Satisfied\n";
    else
          cout<<"Not Satisfied\n";
    return 0;
}
