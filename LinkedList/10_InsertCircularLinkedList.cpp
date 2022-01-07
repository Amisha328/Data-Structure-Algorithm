#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

struct CircularListNode
{
    int data;
    CircularListNode *next;
    CircularListNode(int d)
    {
        data = d;
        next = NULL;
    }
};

// Naive approach
// Time Complexity: O(n)
CircularListNode *N_insertNodeAtHead(CircularListNode *head, int data)
{
    if(head == NULL)
    {
        head = new CircularListNode(data);
        head->next = head;
        return head;
    }
    CircularListNode *temp = new CircularListNode(data);
    CircularListNode *curr = head;
    while(curr->next != head)
        curr = curr->next;
    curr->next = temp;
    temp->next = head;

    return temp;
}

// Effective approach
// Time Complexity: O(1)
CircularListNode *E_insertNodeAtHead(CircularListNode *head, int data)
{
    CircularListNode *temp = new CircularListNode(data);
    if(head == NULL)
    {
        head = temp;
        head->next = head;
        return head;
    }
    // insert after the head
    temp->next = head->next;
    head->next = temp;
    //swap the head node with the new node
    ll newNode = head->data;
    head->data = temp->data;
    temp->data = newNode;

    return head;
}

CircularListNode *sortedInsert(CircularListNode *head, int data)
{
    if(head == NULL)
    {
        head = new CircularListNode(data);
        head->next = head;
        return head;
    }
    if(head->data >= data)
    {
        return E_insertNodeAtHead(head, data);
    }
    CircularListNode *curr = head;
    while(curr->next != head && curr->next->data < data)
        curr = curr->next;

    CircularListNode *temp = new CircularListNode(data);
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

void traverseLinkedlist(CircularListNode *head)
{
    if(head == NULL) return;
    cout<<head->data<<" ";
    for(CircularListNode *temp = head->next; temp != head; temp = temp->next)
    {
        cout << temp->data << " ";
    }
}

signed main(){

    eff;
    
    CircularListNode *head = new CircularListNode(10);
    head->next = new CircularListNode(20);
    head->next->next = new CircularListNode(30);
    head->next->next->next = new CircularListNode(40);
    head->next->next->next->next = head;
    
    head = sortedInsert(head, 5);
    traverseLinkedlist(head);
    cout<<endl;
    head = sortedInsert(head, 25);
    traverseLinkedlist(head);
    cout<<endl;
    head = N_insertNodeAtHead(head, 50);
    traverseLinkedlist(head);
    cout<<endl;
    head = E_insertNodeAtHead(head, 60);
    traverseLinkedlist(head);
    
    return 0;
}