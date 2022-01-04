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

DoublyListNode *insertInBegin(DoublyListNode *head, ll val)
{
    DoublyListNode *temp = new DoublyListNode(val);
    temp->next = head;
    if(head != NULL)
        head->prev = temp;
    
    return temp;
}

DoublyListNode *insertInEnd(DoublyListNode *head, ll val)
{
    DoublyListNode *temp = new DoublyListNode(val);
    if(head == NULL)
        return temp;
    DoublyListNode *curr = head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;

    return head;
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
    
    DoublyListNode *head = NULL;
    head = insertInBegin(head, 10);
    head = insertInBegin(head, 20);
    head = insertInEnd(head, 30);
    head = insertInEnd(head, 40);

    traverseLinkedList(head);

    return 0;
}