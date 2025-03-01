// Merge Two BSTs
// Approach 1: Using vector
// Problem link:
// https://www.codingninjas.com/codestudio/problem-details/h_920474
// https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1/#

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
void BSTtoInorder(Node *root, vector<int> &inorder)
{
	if(!root) return;
	BSTtoInorder(root->left, inorder);
	inorder.push_back(root->data);
	BSTtoInorder(root->right, inorder);
}
vector<int> mergeInorders(vector<int> &a, vector<int> &b)
{
	int i = 0, j = 0, k = 0;
	vector<int> ans(a.size() + b.size());
	while(i < a.size() && j < b.size())
	{
		if(a[i] < b[j])
			ans[k++] = a[i++];
		else
			ans[k++] = b[j++];
	}
	while(i < a.size())
		ans[k++] = a[i++];
	while(j < b.size())
		ans[k++] = b[j++];
	return ans;
}
Node* inorderToBST(vector<int> &arr, int start, int end)
{
	if(start > end) return NULL;
	
	int mid = (start + end) >> 1;
	Node *root = new Node(arr[mid]);
	root->left = inorderToBST(arr, start, mid-1);
	root->right = inorderToBST(arr, mid+1, end);
	
	return root;
}

// TC-> O(m+n) | SC-> O(m+n)
// m and n are number of nodes in BST
Node *mergeBST(Node *root1, Node *root2)
{
	// Step1: Get inorder of BST
	vector<int> inorder1, inorder2;
	BSTtoInorder(root1, inorder1);
	BSTtoInorder(root2, inorder2);
	
	// Step2: Merge the inorders
	vector<int> mergedArray = mergeInorders(inorder1, inorder2);
	
	// Step 3: convert to BST from inorder
	return inorderToBST(mergedArray, 0, mergedArray.size()-1);
}
       