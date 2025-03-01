// Merge K sorted linked lists
// Problem link:
// https://leetcode.com/problems/merge-k-sorted-lists/
// https://practice.geeksforgeeks.org/problems/merge-k-sorted-Linked-lists/1#
// https://www.codingninjas.com/codestudio/problem-details/merge-k-sorted-lists_992772

// merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
            for(int i = 0; i < K; i++){
                    if(arr[i] != NULL) min_heap.push({arr[i]->data, i});
            }
            
            Node* res = new Node(0);
            
            Node* head = res;
            while(!min_heap.empty()){
                head->next = new Node(min_heap.top().first);
                head = head->next;
                int r = min_heap.top().second;
                min_heap.pop();
                if(arr[r]->next != NULL)
                { 
                    min_heap.push({arr[r]->next->data, r});
                    arr[r]->next = arr[r]->next->next;
                }
            }
            
            return res->next;
    }
};

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}