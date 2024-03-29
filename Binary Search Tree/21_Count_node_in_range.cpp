// Problem statement
/*
Given a Binary Search Tree (BST) of integer values and a range [low, high],
return count of nodes where all the nodes under that node (or subtree rooted with that node) 
lie in the given range.
*/
// Problem link: 
#include <bits/stdc++.h>
using namespace std;

// A BST node
struct node {
	int data;
	struct node *left, *right;
};

// A utility function to check if data of root is
// in range from low to high
bool inRange(node* root, int low, int high)
{
	return root->data >= low && root->data <= high;
}

// A recursive function to get count of nodes whose subtree
// is in range from low to high. This function returns true
// if nodes in subtree rooted under 'root' are in range.
bool getCountUtil(node* root, int low, int high, int &count)
{
	// Base case
	if (root == NULL)
		return true;

	// Recur for left and right subtrees
	bool l = getCountUtil(root->left, low, high, count);
	bool r = getCountUtil(root->right, low, high, count);

	// If both left and right subtrees are in range and current node
	// is also in range, then increment count and return true
	if (l && r && inRange(root, low, high)) {
		++count;
		return true;
	}

	return false;
}

// A wrapper over getCountUtil(). This function initializes count as 0
// and calls getCountUtil()
int getCount(node* root, int low, int high)
{
	int count = 0;
	getCountUtil(root, low, high, count);
	return count;
}

// Utility function to create new node
node* newNode(int data)
{
	node* temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return (temp);
}

// Driver program
int main()
{
	// Let us construct the BST shown in the above figure
	node* root = newNode(10);
	root->left = newNode(5);
	root->right = newNode(50);
	root->left->left = newNode(1);
	root->right->left = newNode(40);
	root->right->right = newNode(100);
	/* Let us constructed BST shown in above example
		10
		/ \
	5	 50
	/	 / \
	1	 40 100 */
	int l = 5;
	int h = 45;
	cout << "Count of subtrees in [" << l << ", "
		<< h << "] is " << getCount(root, l, h);
	return 0;
}
