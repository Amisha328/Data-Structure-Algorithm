// Path to Given Node
// Given a Binary Tree A containing N nodes.You need to find the path from Root to a given node B.

// NOTE:
// No two nodes in the tree have same data values.
// You can assume that B is present in the tree A and a path always exists.

// https://www.interviewbit.com/problems/path-to-given-node/

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
bool path(Node* node, vector<int> &arr, int x)
{
    if(!node) return false;
    arr.push_back(node->data);
    if(node->data == x)
        return true;
    if(path(node->left, arr, x) || path(node->right, arr, x))
        return true;
    
    arr.pop_back();
    return false;
}
vector<int> pathRootToNode(Node* A, int B) {
    vector<int> ans;
    path(A, ans, B);
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
    vector<int> path;
    path = pathRootToNode(root, 70);
    for(auto x : path)
          cout<<x<<" ";

    return 0;
}
