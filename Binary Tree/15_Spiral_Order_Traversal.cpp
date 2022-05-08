// Zig-Zag or Spiral Traversal in Binary Tree
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// https://www.codingninjas.com/codestudio/problem-details/spiral-order-traversal-of-a-binary-tree_630521
// https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1/

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
vector<int> spiralTraversal(Node *root)
{
    vector<int> v;
    stack<Node*> s1, s2;
    if(root == NULL) return v;
    
    s2.push(root);
    
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            // Take out a node
            Node *temp = s1.top();
            v.push_back(temp->data);
            s1.pop();
            
            // Push children of the taken out node into s2.
            if(temp -> left) 
                    s2.push(temp->left);
            
            if(temp->right)
                    s2.push(temp->right);
        }   
         
        while(!s2.empty())
        {
            // Take out a node
            Node *temp = s2.top();
            v.push_back(temp->data);
            s2.pop();
            
            // Push children of the taken out node into s1 in reverse order.
            if(temp->right)
                    s1.push(temp->right);
            
            if(temp -> left) 
                    s1.push(temp->left);
            
        }  
    }
    
    return v;
        
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
    vector<int> spiral;
    spiral = spiralTraversal(root);
    for(auto x : spiral)
          cout<<x<<" ";
    return 0;
}