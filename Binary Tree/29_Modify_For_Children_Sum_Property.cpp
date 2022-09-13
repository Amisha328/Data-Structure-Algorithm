// Modify the value of its nodes, such that the tree holds the Children sum property.
// Problem link:
// https://www.codingninjas.com/codestudio/problem-details/childrensumproperty_790723


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
void changeTree(Node * root) {
    // Intuition: 
    // while going down, increase the children values so we make sure to never fall short,
    // then all we have to do is sum both children and replace it in parent.
    if(!root) return;
    int child_sum = 0;
    if(root->left) child_sum += root->left->data;
    if(root->right) child_sum += root->right->data;
    
    // if both children values sum is greater than or equal to parent, make parent's value to children's sum.
    if(child_sum >= root->data)
        root->data = child_sum;

    // if both children sum is less than parent, make children's value to parent's value.
    else
    {
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }
    
    // recursively go left and right. Traversal type: DFS.
    changeTree(root->left);
    changeTree(root->right);
    
    int bottomUp = 0;
    // when coming back up the tree, take children sum and replace it in parent.
    if(root->left) bottomUp += root->left->data;
    if(root->right) bottomUp += root->right->data;
    if(root->left || root->right) root->data = bottomUp;
}  

vector<int> preorder;
vector<int> preorderTraversal(Node* root) 
{
        if(root == NULL) return preorder;
        preorder.push_back(root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return preorder;
}

signed main(){
    eff;
    Node *root = new Node(50);
    root->left = new Node(7);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(1);
    root->right->right = new Node(30);
    
    changeTree(root);

    // Preorder Traversal
    vector<int> preorder;
    preorder = preorderTraversal(root);
    for(auto x : preorder)
          cout<<x<<" ";

    return 0;
}
