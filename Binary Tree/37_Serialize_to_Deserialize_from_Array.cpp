// Serialization is to store a tree in an array so that it can be later restored and,
// Deserialization is reading tree back from the array.
// Pronlem link:
// https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1#

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// TC-> O(n) | SC->O(n)
class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> ans;
    vector<int> serialize(Node *root) 
    {
        //Your code here
        if(root == NULL)
        {
            ans.push_back(-1);
            return ans;
        }
        
        ans.push_back(root->data);
        serialize(root->left);
        serialize(root->right);
        
        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    int i = 0;;
    Node * deSerialize(vector<int> &A)
    {
       if(i == A.size()) return NULL;
       int val = A[i];
       i++;
       if(val == -1) return NULL;
       
       Node *root = new Node(val);
       root->left = deSerialize(A);
       root->right = deSerialize(A);
       return root;
    }

};
