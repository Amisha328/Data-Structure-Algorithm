// Detect Cycle in linked list
// https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1#
// https://leetcode.com/problems/linked-list-cycle/
// https://www.codingninjas.com/codestudio/problem-details/cycle-detection-in-a-singly-linked-list_628974


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


class Solution
{
    public:
    // TC -> O(n) | SC-> O(1)
    bool detectLoop(Node* head)
    {
        // your code here
        if(head == NULL) return false;
        Node *slow = head, *fast = head;
        
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        
        return false;
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
        if(ob.detectLoop(head) )
            cout<< "True\n";
        else
            cout<< "False\n";
	return 0;
}
