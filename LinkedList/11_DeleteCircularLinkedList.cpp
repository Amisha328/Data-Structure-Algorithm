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

// Naive Solution - O(n)
CircularListNode *N_deleteNodeAtHead(CircularListNode *head)
{
    if(head == NULL) return NULL;
    // single node in Linked List
    if(head->next == head)
    {
        delete head;
        return NULL;
    }
    CircularListNode *curr = head;
    while(curr->next != head)
        curr = curr->next;
        
    curr->next = head->next;
    delete head;
    return curr->next;
}

// Effective Solution - O(1)
CircularListNode *E_deleteNodeAtHead(CircularListNode *head)
{
    if(head == NULL) return NULL;
    if(head->next == head)
    {
        delete head;
        return NULL;
    }
    head->data = head->next->data;
    CircularListNode *temp = head->next;
    head->next = head->next->next;
    delete temp;
    return head;
}

// Time Complexity: O(k)
CircularListNode *deleteKthNode(CircularListNode *head, int k)
{
    if(head == NULL) return NULL;
    if(k == 1) return E_deleteNodeAtHead(head);
    CircularListNode *curr = head;
    for(int i = 0; i < k-2; i++)
        curr = curr->next;
    
    CircularListNode *temp = curr->next;
    curr->next = temp->next;
    delete temp;
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
    head->next->next->next->next = new CircularListNode(50);
    head->next->next->next->next->next = head;
    
    head = N_deleteNodeAtHead(head);
    traverseLinkedlist(head);
    cout<<endl;
    head = E_deleteNodeAtHead(head);
    traverseLinkedlist(head);
    cout<<endl;
    head = deleteKthNode(head, 3);
    traverseLinkedlist(head);
    
    return 0;
}