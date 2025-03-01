// Left View of Binary Tree
// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
// https://www.codingninjas.com/codestudio/problem-details/left-view-of-binary-tree_625707

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
int currLevel = 0;
void traversal(Node* node, vector<int> &ans, int level)
{
        if(node == NULL) return;
        if(currLevel < level)
        {
            ans.push_back(node->data);
            currLevel = level;
        }
        traversal(node->left, ans, level+1);
        traversal(node->right, ans, level+1);
}
vector<int> leftSideView(Node* root) 
{
        // Recursive solution
        vector<int> ans;
        traversal(root, ans, 1);
        return ans;
        
        
        /*
        // Iterative Solution
          vector<int> ans;
          if(root == NULL) return ans;
          
          queue<Node*> q;
          q.push(root);
          
          while(!q.empty())
          {
             int c = q.size();
             for(int i = 0; i < c; i++)
             {
                    Node *curr = q.front();
                    q.pop();
                    
                    if(i == 0)
                    ans.push_back(curr->data);
                    
                    if(curr->left)
                    q.push(curr->left);
                    
                    if(curr->right)
                    q.push(curr->right);
             }
          }
          return ans;
        */
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
    vector<int> left_elements;
    left_elements = leftSideView(root);
    for(auto x : left_elements)
          cout<<x<<" ";
    return 0;
}