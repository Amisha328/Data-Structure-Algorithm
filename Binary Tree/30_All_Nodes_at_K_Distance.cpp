// All Nodes Distance K in Binary Tree
// Problem link:
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1/#

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

// Mark each node to its parent to traverse upwards
    void markParent(Node *root, map<Node*, Node*> &track_parent)
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            if(curr->left)
            {
                track_parent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                track_parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(Node* root, Node* target, int k) {
        map<Node*, Node*> track_parent; //  node -> parent
        markParent(root, track_parent);
        
        map<Node*, bool> visited;
        queue<Node*> q;
        // We will do a BFS traversal starting from the target node
        q.push(target);
        visited[target] = true;
        int curr_dis = 0;
        while(!q.empty())
        {
            int size = q.size();
            if(curr_dis++ == k) break;
            for(int i = 0; i < size; i++)
            {
                Node * curr = q.front();
                q.pop();
                // As long as we have not seen our node previously, Traverse left,until reached Kth distance
                if(curr->left && !visited[curr->left])
                {
                   q.push(curr->left);
                   visited[curr->left] = true;
                }
                // As long as we have not seen our node previously, Traverse right, until reached Kth distance
                if(curr->right && !visited[curr->right])
                {
                   q.push(curr->right);
                   visited[curr->right] = true;
                }
                // As long as we have not seen our node previously, Traverse up, ntil reached Kth distance
                if(track_parent[curr] && !visited[track_parent[curr]])
                {
                    q.push(track_parent[curr]);
                    visited[track_parent[curr]] = true;
                }
            }
        }
        // when reached Kth distance, break out of BFS loop and remaining node's values in our queue is our result
        vector<int> res;
        while(!q.empty())
        {
            Node *node = q.front();
            q.pop();
            res.push_back(node->data);
        }
        return res;
}

signed main(){
    eff;
    Node *root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    Node *target = new Node(5);
    int k = 2;
    vector<int> res;
    res = distanceK(root, target, k);
    for(auto x : res)
          cout<<x<<" ";

    return 0;
}