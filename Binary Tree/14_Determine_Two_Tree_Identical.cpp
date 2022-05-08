// Determine if Two Trees are Identical 
// https://leetcode.com/problems/same-tree/
// https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1#

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

bool isIdentical(Node *r1, Node *r2)
{
        //Your Code here
        if(r1 == NULL || r2 == NULL)
            return (r1 == r2);
        
        if(r1->data != r2->data)
            return false;
        
        return (isIdentical(r1->left, r2->left), isIdentical(r1->right, r2->right));
}

signed main(){
    eff;
    Node *root1 = new Node(5);
    root1->right = new Node(6);
    root1->right->left = new Node(-5);
    root1->right->right = new Node(5);

    Node *root2 = new Node(5);
    root2->right = new Node(6);
    root2->right->left = new Node(-5);
    root2->right->right = new Node(5);     

   if(isIdentical(root1, root2))
          cout<<"Yes"<<endl;
   else
          cout<<"No"<<endl;
    return 0;
}