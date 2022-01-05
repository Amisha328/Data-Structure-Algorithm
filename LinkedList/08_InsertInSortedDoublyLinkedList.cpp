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

DoublyListNode* sortedInsert(DoublyListNode* head, int data) {
    if(head == NULL)
        return new DoublyListNode(data);
    
    DoublyListNode *temp = new DoublyListNode(data);
    if(data < head->data)
    {
        temp->next = head;
        head->prev = temp;
        
        return temp;
    }
    else
    {
        DoublyListNode *curr = head;
    
        while(curr->next != NULL && curr->next->data < data)
            curr = curr->next;
        
        if(curr->next == NULL)
        {
            curr->next = temp;
            temp->prev = curr;
            
            return head;
        }
        temp->next = curr->next;
        curr->next->prev = temp;
        curr->next = temp;
        temp->prev = curr;
        
    }
    
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
    
    DoublyListNode *head = new DoublyListNode(10);
    DoublyListNode *temp1 = new DoublyListNode(20);
    DoublyListNode *temp2 = new DoublyListNode(30);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;

    head = sortedInsert(head, 25);
    traverseLinkedList(head);

    return 0;
}