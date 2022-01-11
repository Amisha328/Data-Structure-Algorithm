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

ListNode *reverseLinkedList(ListNode *head)
{
    if(head == NULL)
        return NULL;
    if(head->next == NULL)
        return head;
    
    ListNode *prev = NULL, *curr = head, *next = NULL;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

signed main(){
    eff;
    
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);
    
    head = reverseLinkedList(head);
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    return 0;
}

// Time Complexity: O(n)