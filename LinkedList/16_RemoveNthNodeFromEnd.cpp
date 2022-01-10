// Find the Nth Node from the end in Singly Linked List

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

struct ListNode
{
    ll data;
    ListNode *next; // self-referential pointer

    ListNode(ll x)
    {
        data = x;
        next = NULL;
    }
};

void traverseLinkedList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
        ListNode* slow = head, *fast = head;
        ListNode* pre;

       //Let fast pointer take a n-1 node lead in the beginning
       for(int i = 1; i <= n-1; i++)
       {
           if(fast == NULL) return NULL;
           fast = fast->next;
       }
       //Now, let both slow and fast travel forward until fast->next == NULL
       while(fast->next !=NULL ){
           pre = slow;
           slow = slow->next;
           fast = fast->next;
       }
        
       //Handing the case when slow is at the head
       if(slow == head){
           head = head->next;
           return head;
       }
        
        // slow is in the required place (nth node from the end)
        // pre is one node before slow
       pre->next = pre->next->next;
       return head;
}

signed main(){
    eff;
    
    ListNode *head = new ListNode(20);
    head->next = new ListNode(30);
    head->next->next = new ListNode(40);
    head->next->next->next = new ListNode(50);
    head->next->next->next->next = new ListNode(60);
    
    head = removeNthFromEnd(head,2);
    traverseLinkedList(head);
    return 0;
}

// Time Complexity: O(n)