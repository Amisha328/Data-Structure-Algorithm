// Root to Leaf Paths 
// https://practice.geeksforgeeks.org/problems/root-to-leaf-paths/1/#
// https://leetcode.com/problems/binary-tree-paths/
// https://www.codingninjas.com/codestudio/problems/all-root-to-leaf-paths-in-binary-tree_983599

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
void solve(Node *node, vector<vector<int>> &ans, vector<int> &v)
{
     if(node == NULL)
        return;
     v.push_back(node->data);
     if(node->left == NULL && node->right == NULL)
     {
        ans.push_back(v);
        v.pop_back();
        return;
     }
     solve(node->left, ans, v);
     solve(node->right, ans, v);
     v.pop_back();
     return;
}
vector<vector<int>> pathRootToLeaf(Node* root)
{
    // Code here
    vector<vector<int>> ans;
    vector<int> v;
    solve(root, ans, v);
    return ans;
}

signed main(){
    eff;
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
    vector<vector<int>> path;
    path = pathRootToLeaf(root);
    for(auto x : path)
    {
          for(auto y: x)
            cout<<y<<" ";
          cout<<endl;
    }
    return 0;
}