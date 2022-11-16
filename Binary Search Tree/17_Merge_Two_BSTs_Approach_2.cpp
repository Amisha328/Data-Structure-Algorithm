// Merge Two BSTs
// Approach 2: Using Linked List
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
void BSTtoDLL(Node *root, Node* &head)
{
	if(!root) return;
	BSTtoDLL(root->right, head);
	root->right = head;
	if(head != NULL)
		head->left = root;
	head = root;
	BSTtoDLL(root->left, head);
}

Node *mergeSortedDLL(Node *head1, Node *head2)
{
	if(!head1) return head2;
	if(!head2) return head1;
	Node *head = NULL;
	Node *tail = NULL;
	
	while(head1 != NULL && head2 != NULL)
	{
		if(head1->data < head2->data)
		{
			if(head == NULL)
			{
				head = tail = head1;
				head1 = head1->right;
			}
			else
			{
				tail->right = head1;
				head1->left = tail;
				tail = head1;
				head1 = head1->right;
			}
		}
		else
		{
			if(head == NULL)
			{
				head = tail = head2;
				head2 = head2->right;
			}
			else
			{
				tail->right = head2;
				head2->left = tail;
				tail = head2;
				head2 = head2->right;
			}
		}
	}
	while(head1)
	{
		tail->right = head1;
		head1->left = tail;
		tail = head1;
		head1 = head1->right;
	}
	while(head2)
	{
		tail->right = head2;
		head2->left = tail;
		tail = head2;
		head2 = head2->right;
	}
	
	return head;
}
int countNodes(Node *&head)
{
	int count = 0;
	Node *curr = head;
	while(curr)
	{
		count++;
		curr = curr->right;
	}
	return count;
}
Node *convertDLLtoBST(Node *&head, int n)
{
	if(n <= 0 || !head) return NULL;
	Node *left = convertDLLtoBST(head, n/2);
	Node *root = head;
	root->left = left;
	head = head->right;
	root->right = convertDLLtoBST(head, n-n/2-1);
	return root;
}

// TC-> O(m+n) | SC-> O(h1 + h2)
// m and n are number of nodes in BST
// h1 and h2 are height of BSTs.
Node *mergeBST(Node *root1, Node *root2)
{
	// Step1: convert BST to DLL
	Node * head1 = NULL, *head2 = NULL;
	BSTtoDLL(root1, head1);
	head1->left = NULL;
	BSTtoDLL(root2, head2);
	head2->left = NULL;
	
	// Step2: merge two DLL
	Node *mergedDLL = mergeSortedDLL(head1, head2);
	
	// Step3: convert sorted DLL to BST
	return convertDLLtoBST(mergedDLL, countNodes(mergedDLL));
}