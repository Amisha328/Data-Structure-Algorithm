// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#
// https://leetcode.com/problems/linked-list-cycle-ii/
// https://www.codingninjas.com/codestudio/problems/detect-and-remove-cycle_920523?leftPanelTab=0 

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

class Solution
{
    public:
    void removeLoop(Node* head)
    {
        if(head == NULL) return;
        
        Node *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        
        if (!(fast && fast->next)) return;
        
        if(slow == head)  // 1 1 1 -1 pos = 0 
        {
            while(fast->next != slow)
                fast = fast->next;
                
            fast->next = NULL;
            return;
        }
        fast = head;
        while(slow->next != fast->next)
        {
             slow = slow->next;
             fast = fast->next;
        }
        
        slow->next = NULL;
    }
};
int main()
{
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
	return 0;
}
  // } Driver Code Ends