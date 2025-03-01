// Minimum time taken to BURN the Binary Tree from a Node or Leaf
// Problem link:
// https://www.codingninjas.com/codestudio/problem-details/time-to-burn-tree_630563
// https://practice.geeksforgeeks.org/problems/burning-tree/1/?category#

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

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
Node* markParent(Node* &node, map<Node*, Node*> &mp, int start)
{
    Node *target;
    queue<Node*> q;
    q.push(node);
    while(!q.empty())
    {
        Node* curr = q.front();
        q.pop();
        if(curr->data == start)
            target = curr;
        if(curr->left)
        {
            q.push(curr->left);
            mp[curr->left] = curr;
        }
        if(curr->right)
        {
            q.push(curr->right);
            mp[curr->right] = curr;
        }
    }
    return target;   
}
int findTimetoBurn(map<Node*, Node*> &mp, Node* &target)
{
    map<Node*, bool> visited;
    queue<Node*> q;
    q.push(target);
    visited[target] = true;
    int time = 0;
    while(!q.empty())
    {
        int flag = 0; // if flag gets 1 at any time means atleast 1 adjacent node is burned.
        int size = q.size();
        for(int i = 0; i < size; i++)
        {
            Node* node = q.front();
            q.pop();
            // Traverse up, left, right until 1 radial level (adjacent nodes) are burned and increment our timer.
            if(node->left && !visited[node->left])
            {
                flag = 1;
                q.push(node->left);
                visited[node->left] = true;
            }
            if(node->right && !visited[node->right])
            {
                flag = 1;
                q.push(node->right);
                visited[node->right] = true;
            }
            if(mp[node] && !visited[mp[node]])
            {
                flag = 1;
                q.push(mp[node]);
                visited[mp[node]] = true;
            }
        }
        if(flag) time++;
    }
    return time;
}
int timeToBurnTree(Node* root, int start)
{
    map<Node*, Node*> track_parent;
    Node* target = markParent(root, track_parent, start);
    return findTimetoBurn(track_parent, target);
}

signed main(){
    eff;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->right = new Node(7);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    int start = 2;
    cout<<timeToBurnTree(root, start);
    return 0;
}