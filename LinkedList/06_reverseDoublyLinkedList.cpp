#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

struct DoublyListNode
{
    ll data;
    DoublyListNode *prev, *next; // self-referential pointer

    DoublyListNode(ll x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

DoublyListNode *reverseDoublyLinkedList(DoublyListNode *head)
{
    DoublyListNode *prev = NULL, *curr = head;
    while (curr != NULL)
    {
        // swapping part
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        // moving to next node
        curr = curr->prev;
    }
    return prev->prev;
}

void traverseLinkedList(DoublyListNode *head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

signed main(){
    eff;
    
    DoublyListNode *head = new DoublyListNode(10);
    DoublyListNode *temp1 = new DoublyListNode(20);
    DoublyListNode *temp2 = new DoublyListNode(30);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    
    head = reverseDoublyLinkedList(head);

    traverseLinkedList(head);

    return 0;
}