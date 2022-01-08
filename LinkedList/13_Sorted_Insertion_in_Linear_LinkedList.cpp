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

ListNode *sortedInsert(ListNode *head, ll data)
{
    ListNode *temp = new ListNode(data);
    if(head == NULL)
         return temp;
    if(data < head->data)
    {
        temp->next = head;
        return temp;
    }
    ListNode *curr = head;
    while(curr->next != NULL && data > curr->next->data)
    {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

signed main(){
    eff;
    
    ListNode *head = new ListNode(20);
    head->next = new ListNode(30);
    head->next->next = new ListNode(40);
    head->next->next->next = new ListNode(50);
    head->next->next->next->next = new ListNode(60);
    
    head = sortedInsert(head, 45);
    traverseLinkedList(head);
    cout<<endl;
    head = sortedInsert(head, 10); 
    traverseLinkedList(head);

    return 0;
}