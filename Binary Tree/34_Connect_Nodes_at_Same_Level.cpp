// Connect Nodes at Same Level 
//  Problem link:
// https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1#
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// https://www.codingninjas.com/codestudio/problem-details/populating-next-right-pointers-in-each-node_1263696

#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
};

void connect(Node *root)
{
       // Your Code Here
       if(root == NULL) return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 1; i <= size; i++)
            {
                Node *curr = q.front();
                q.pop();
                if(i != size)
                    curr->nextRight = q.front();
                else
                    curr->nextRight = NULL;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }    
} 