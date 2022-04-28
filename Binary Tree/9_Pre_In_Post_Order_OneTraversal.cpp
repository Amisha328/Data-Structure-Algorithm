// Preorder Inorder Postorder Traversals in One Traversal

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

void preInPostTraversal(Node* root, vector<int> &preorder, vector<int> &inorder, vector<int> &postorder) 
{
     stack<pair<Node*, int>> s;
     s.push({root, 1});
     if(root == NULL) return;
     while(!s.empty())
     {
               auto it = s.top();
               s.pop();
              // this is part of pre
              // increment 1 to 2 
              // push the left side of the tree
               if(it.second == 1)
               {
                         preorder.push_back(it.first->data);
                         it.second++;
                         s.push(it);
                         if(it.first->left)
                              s.push({it.first->left, 1});
               }
               // this is a part of in 
               // increment 2 to 3 
               // push right
               else if(it.second == 2)
               {
                         inorder.push_back(it.first->data);
                         it.second++;
                         s.push(it);
                         if(it.first->right)
                              s.push({it.first->right, 1}); 
               }
              // don't push it back again 
               else
                    postorder.push_back(it.first->data);
     }   
}

signed main(){
    eff;
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    vector<int> pre, in, post;
    preInPostTraversal(root, pre, in, post);
    for(auto x: pre)
          cout<<x<<" ";
    cout<<endl;
    for(auto x: in)
          cout<<x<<" ";
    cout<<endl;
    for(auto x: post)
          cout<<x<<" ";
    
    return 0;
}
