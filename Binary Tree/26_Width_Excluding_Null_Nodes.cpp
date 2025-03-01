// Maximum Width In Binary Tree
// The width of one level is defined as the length between the leftmost and the rightmost,
// non-null nodes in the level, where the null nodes in between the leftmost and rightmost 
// are excluded into length calculation.

//  Problem link:
// https://www.codingninjas.com/codestudio/problem-details/maximum-width-in-binary-tree_763671
// https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1/

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
// TC -> O(n) || SC->O(n)

int getMaxWidth(Node *root)
{
    if(!root) return 0;
        queue<Node*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty())
        {
            int size = q.size();
            ans = max(ans, size);
            for(auto i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        return ans;
}

signed main(){
    eff;
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->left->right = new Node(70);
    root->right->left = new Node(50);
    root->right->right = new Node(60);
    cout<<getMaxWidth(root)<<endl;
    return 0;
}