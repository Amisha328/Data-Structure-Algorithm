// Sum of Left Leaves
// https://leetcode.com/problems/sum-of-left-leaves/
// https://practice.geeksforgeeks.org/problems/sum-of-left-leaf-nodes/1/#

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vi vector<int>

struct Node
{
    int val;
   Node *left, *right;

    Node(int k)
    {
        val = k;
        left = right = NULL;
    }
};

int findLeave(Node *root, bool isLeft){
        if(root == NULL)
            return 0;
        if(isLeft && root->left == NULL && root->right == NULL)
          return root->val;

        return findLeave(root->left, true) + findLeave(root->right, false);
}
int sumOfLeftLeaves(Node* root) {
        return findLeave(root, false);
}
signed main(){
    eff;
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    cout<<sumOfLeftLeaves(root);
    return 0;
}