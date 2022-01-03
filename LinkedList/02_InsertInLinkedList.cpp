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

ListNode *insertInBegin(ListNode *head, ll x)
{
    ListNode *newNode = new ListNode(x);
    newNode->next = head;
    return newNode;
}

ListNode *insertInEnd(ListNode *head, ll x)
{
    if(head == NULL)
    {
        return new ListNode(x);
    }
    ListNode *curr = head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    ListNode *newNode = new ListNode(x);
    curr->next = newNode;
    return head;
}

ListNode *insertAtPosition(ListNode *head, ll x, ll pos)
{
    ListNode *newNode = new ListNode(x);
    if(pos == 1)
    {
        newNode->next = head;
        return newNode;
    }
    ListNode *curr = head;
    for(ll i = 1; i < pos - 1 && curr != NULL; i++)
    {
        curr = curr->next;
    }
    if(curr == NULL) // if pos is greater than length of linked list
        return head;

    newNode->next = curr->next;
    curr->next = newNode;
    return head;

}

signed main(){
    eff;
    
    ListNode *head = NULL;
    head = insertInEnd(head, 10);
    head = insertInBegin(head, 20);
    head = insertInBegin(head, 30);
    head = insertInEnd(head, 40);
    head = insertInEnd(head, 50);
    head = insertAtPosition(head, 60, 4);

    traverseLinkedList(head);

    return 0;
}