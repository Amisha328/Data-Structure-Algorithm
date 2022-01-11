// Given an LinkedList of integers, reverse the Linked List in groups of size k.
// Variation: 1
// example:
// Input
// 1->2->3->4->5
// k = 3
// Output
// 3->2->1->4->5

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

int length(ListNode* head)
{
    int len = 0;
    while(head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

// Recursive approach
ListNode *reverseInGroup(ListNode *head, int k)
{
    if(head == NULL)
        return NULL;
    int x = length(head);
    if(x < k)
        return head;

    ListNode *prev = NULL, *curr = head, *next = NULL;
    int count = 0;
    while(curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(curr != NULL)
        head->next = reverseInGroup(next, k);

    return prev;
}

signed main(){
    eff;
    
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);
    
    head = reverseInGroup(head,3);
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    return 0;
}

// Time Complexity: O(n)
// Auxiliary Space: O(n)

// https://leetcode.com/problems/reverse-nodes-in-k-group/