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

DoublyListNode *deleteInBegin(DoublyListNode *head)
{
    if(head == NULL)
        return NULL;

    if(head->next == NULL)
    {
        delete head;
        return NULL;
    }

    DoublyListNode *temp = head;
    head = head->next;
    head->prev = NULL; 
    delete temp;

    return head;
}

DoublyListNode *deleteInEnd(DoublyListNode *head)
{
    if(head == NULL)
        return NULL;
    if(head->next == NULL)
    {
        delete head;
        return NULL;
    }
    DoublyListNode *curr = head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->prev->next = NULL;
    delete curr;
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
    
    head = deleteInBegin(head);
    traverseLinkedList(head);
    cout<<endl;
    head = deleteInEnd(head);
    traverseLinkedList(head);
    return 0;
}