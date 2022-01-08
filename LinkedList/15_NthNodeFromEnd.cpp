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

// Move the first pointer n position ahead
// Move the second pointer from the head
// when first pointer reaches the NULL, second pointer must be at the nth position from the end
void NthNode(ListNode *head, int n)
{
    ListNode *slow = head, *fast = head;
    for(int i = 0; i < n; i++)
    {
        if(fast == NULL) return;
        fast = fast->next;
    }
    while(fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    cout<<slow->data<<endl;
}

signed main(){
    eff;
    
    ListNode *head = new ListNode(20);
    head->next = new ListNode(30);
    head->next->next = new ListNode(40);
    head->next->next->next = new ListNode(50);
    head->next->next->next->next = new ListNode(60);
    
    NthNode(head,2);

    return 0;
}

// Time Complexity: O(n)