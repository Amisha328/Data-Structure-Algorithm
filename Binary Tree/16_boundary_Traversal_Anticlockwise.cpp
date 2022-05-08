// Boundary Traversal of binary tree [ Anti-clockwise]
// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1/#
// https://www.codingninjas.com/codestudio/problem-details/boundary-traversal_790725

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
    bool isLeaf(Node *node)
    {
        return (!(node->left) && (!node->right));
    }
    void leftBoundary(Node *node, vector<int> &res)
    {
        Node *curr = node->left;
        while(curr)
        {
            if(!isLeaf(curr))  res.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    void addLeaves(Node *node, vector<int> &res)
    {
        if(isLeaf(node))
        {
              res.push_back(node->data);
              return;
        }
        if(node->left) addLeaves(node->left, res);
        if(node->right) addLeaves(node->right, res);
    }
    void rightBoundary(Node *node, vector<int> &res)
    {
        Node *curr = node->right;
        stack<int> s;
        while(curr)
        {
            if(!isLeaf(curr))  s.push(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
    }
    vector <int> boundaryTraversal(Node *root)
    {
        vector<int> res;
        if(!root) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        leftBoundary(root, res);
        addLeaves(root, res);
        rightBoundary(root, res);
        return res;
    }
signed main(){
    eff;
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    root->left->left = new Node(60);
    root->left->right = new Node(70);
    vector<int> boundary_elements;
    boundary_elements = boundaryTraversal(root);
    for(auto x : boundary_elements)
          cout<<x<<" ";
    return 0;
}