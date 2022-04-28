// Binary Tree Level Order Traversal Line by Line
// https://leetcode.com/problems/binary-tree-level-order-traversal/

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

vector<vector<int>> levelOrder(Node* root) 
{
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> level;
            int size = q.size();
            for(int i = 1; i <= size; i++)
            {
                Node *curr = q.front();
                q.pop();
                level.push_back(curr->data);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            ans.push_back(level);
        }
        return ans;
}

signed main(){
    eff;
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    vector<vector<int>> ans;
    ans = levelOrder(root);
    for(int i = 0 ; i < ans.size(); i++)
    {
        for (int j = 0; j < ans.at(i).size(); j++)
             cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

// Time Complexity: O(n)
// Auxiliary Space: O(height of tree)
