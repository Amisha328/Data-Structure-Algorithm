// Level order traversal 
// https://practice.geeksforgeeks.org/problems/level-order-traversal/1#
// https://www.codingninjas.com/codestudio/problems/level-order-traversal_796002?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos&leftPanelTab=1

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

vector<int> levelOrder(Node* root)
{
      vector<int> ans;
       if(root == NULL) return ans;
       queue<Node*> q;
       q.push(root);
       while(!q.empty())
       {
           Node *curr = q.front();
           ans.push_back(curr->data);
           q.pop();
           if(curr->left)
            q.push(curr->left);
           if(curr->right)
            q.push(curr->right);
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

    vector<int> ans;
    ans = levelOrder(root);
    for(auto x: ans)
          cout<<x<<" ";
    return 0;
}

// Time Complexity: O(n)
// Auxiliary Space: O(height of tree)

