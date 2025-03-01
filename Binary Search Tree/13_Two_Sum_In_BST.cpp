// Two Sum In BST
// Problem link:
// https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1/#
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// https://www.codingninjas.com/codestudio/problem-details/pair-sum-in-bst_920493

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

/*
// Approach 1: Storing the Inorder Traversal and finding sum of pair using two pointer.
// TC-> O(N)[to store inorder] + O(N)[to calculate sum]
// SC-> O(N) [ vector to store inorder traversal]

class Solution {
    vector<int> vec;  // store the inorder traversal
public:
   // We are using inorder traversal as Inorder Traversal of BST is always sorted.
    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        vec.push_back(root->data);
        inorder(root->right);
    }
    
    bool findTarget(Node* root, int k) {
        inorder(root);
        int l = 0, r = vec.size()-1;
        while (l < r) {
			// if sum of two pointer values is equal to k return true
            if (vec[l] + vec[r] == k) return true;
			// if sum is less tha k so we need to inc the value so we will move left pointer towards right.
            else if (vec[l] + vec[r] < k) l++;
			// if sum is greater tha k so we need to dec the value so we will move right pointer towards left.
            else r--;
            }
        }
        return false;
    }
};

*/

// Approach 2: Using Iterators to find the next from beginning and before from end in inorder traversal.
// TC-> O(N) [under worst case we will traverse all the nodes]
// SC-> O(H) x 2 [one for next and other for before]

class BSTIterator
{
    stack<Node*> st;
    bool reverse = true;
    // reverse -> true [before]
    // reverse -> false [next]
    public:
    BSTIterator(Node *root, bool isReversed){
        reverse = isReversed;
        pushAll(root);
    }
    int next()
    {
        Node *root = st.top();
        st.pop();
        if(!reverse) pushAll(root->right);
        else pushAll(root->left);
        return root->data;
    }
    void pushAll(Node *root)
    {
        while(root)
        {
            st.push(root);
            if(!reverse) root = root->left;
            else root = root->right;
        }
    }
    
};
class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int target)
    {
    //add code here.
        if(!root) return 0;
         BSTIterator left(root, false);
         BSTIterator right(root, true);
         
         int i = left.next();
         int j = right.next();
         while(i < j)
         {
             if(i + j == target) return 1;
             else if(i + j < target) i = left.next();
             else j = right.next();
         }
         return 0;
    }
};