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
    
    traverseLinkedlist(head);

    return 0;
}