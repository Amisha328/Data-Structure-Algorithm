// Flattening a Linked List

/*
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
          (i) a next pointer to the next node,
          (ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer
*/

// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#
// https://www.codingninjas.com/codestudio/problem-details/flatten-a-linked-list_1112655


#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

// // ################################### MAIN LOGIC ########################################################

//TC -> O(N*N*M) | SC-> O(N*M)
Node *mergeTwoLinkedList(Node *a, Node *b)
{
    if(a == NULL) return b;
    if(b == NULL) return a;
    
    Node* result;
    if(a->data < b->data){
        result = a;
        result->bottom = mergeTwoLinkedList(a->bottom , b);
    }
    else{
        result = b;
        result->bottom = mergeTwoLinkedList(a,b->bottom);
    }
    result->next = NULL;
    return result;
}

Node *flatten(Node *root)
{
   // Your code here
   if(root == NULL || root->next == NULL) return root;
   
   // recur to the last node
   root->next = flatten(root->next);
   
   // merge the two nodes
   root = mergeTwoLinkedList(root, root->next);
   
   return root;
}


// // #############################################################################################

// code part of GFG


void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}


int main(void) {

    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
          int work[n];
	for(int i=0;i<n;i++)
            cin>>work[i];
	for(int i=0;i<n;i++){
	          m=work[i];
		--m;
		int data;
		scanf("%d",&data);
		temp = new Node(data);
		temp->next = NULL;
		temp->bottom = NULL;
			
		if(flag)
                    {
			head = temp;
			pre = temp;
			flag = 0;
			flag1 = 1;
		}
		else{
			pre->next = temp;
			pre = temp;
			flag1 = 1;
		}
		for(int j=0;j<m;j++){
				
			int temp_data;
			scanf("%d",&temp_data);
			tempB = new Node(temp_data);

			if(flag1){
				temp->bottom=tempB;
				preB=tempB;
				flag1=0;
			}
			else{
				preB->bottom=tempB;
				preB=tempB;
			}
		}
	}
	Node *fun = head;
	Node *fun2=head;

          Node* root = flatten(head);
          printList(root);
          cout<<endl;

	return 0;
}


