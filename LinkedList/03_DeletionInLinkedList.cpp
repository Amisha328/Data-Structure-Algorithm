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

ListNode *deleteInBegin(ListNode *head)
{
    if(head == NULL)
    {
        return NULL;
    }
    ListNode *temp = head->next;
    delete head;
    return temp;
}

ListNode *deleteInEnd(ListNode *head)
{
    if(head == NULL)
        return NULL;
    if(head->next == NULL)
    {
        delete head;
        return NULL;
    }
    ListNode *curr = head;
    while(curr->next->next != NULL)
    {
        curr = curr->next;
    }

    ListNode *temp = curr->next;
    curr->next = NULL;
    delete temp;
    return head;
}

ListNode *deleteAtPosition(ListNode *head, ll pos)
{
    if(head == NULL)
        return NULL;
    if(pos == 0)
    {
        ListNode *temp = head->next;
        delete head;
        return temp;
    }
    ListNode *curr = head;
    for(ll i = 0; i < pos - 1 && curr != NULL; i++)
    {
        curr = curr->next;
    }
    if(curr == NULL)
        return head;
    else 
    {
       ListNode *temp = curr->next;
       curr->next = temp->next;
       delete temp;
       
       return head; 
    }
}
    

signed main(){
    eff;
    
    ListNode *head = new ListNode(20);
    head->next = new ListNode(30);
    head->next->next = new ListNode(40);
    head->next->next->next = new ListNode(50);

    head = deleteInBegin(head);
    traverseLinkedList(head);
    cout<<endl;
    head = deleteInEnd(head);
    traverseLinkedList(head);
    cout<<endl;
    head = deleteAtPosition(head, 1);
    traverseLinkedList(head);

    return 0;
}