// Binary Search Tree Iterator
// Problem link:
// https://leetcode.com/problems/binary-search-tree-iterator/

#include<bits/stdc++.h>
using namespace std;


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

// TC->O(1) [on average] | SC->O(H)
class BSTIterator {
public:
    stack<Node*> st;
    BSTIterator(Node* root) {
        pushAll(root);
    }
    
    int next() {
        Node *temp = st.top();
        st.pop();
        if(temp->right) pushAll(temp->right);
        return temp->data;
    }
    
    bool hasNext() {
        return (!st.empty());
    }
    
    void pushAll(Node *root)
    {
        while(root)
        {
            st.push(root);
            root = root->left;
        }
    }
};