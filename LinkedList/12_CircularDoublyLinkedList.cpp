#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

struct CircularDoublyListNode
{
    int data;
    CircularDoublyListNode *prev, *next;
    CircularDoublyListNode(int d)
    {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

CircularDoublyListNode *insertAtHead(CircularDoublyListNode *head, int data)
{
    CircularDoublyListNode *temp = new CircularDoublyListNode(data);
    if(head == NULL)
    {
        head = temp;
        head->next = head;
        head->prev = head;
        return head;
    }
    temp->prev = head->prev;
    temp->next = head;
    head->prev->next = temp;
    head->prev = temp;
    return temp;
}

void traverseLinkedlist(CircularDoublyListNode *head)
{
    if(head == NULL) return;
    cout<<head->data<<" ";
    for(CircularDoublyListNode *temp = head->next; temp != head; temp = temp->next)
    {
        cout << temp->data << " ";
    }
}

signed main(){
    eff;
    
    CircularDoublyListNode *head = NULL;
    head = insertAtHead(head, 40);
    head = insertAtHead(head, 30);

    traverseLinkedlist(head);

    return 0;
}