#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 

struct ListNode
{
    ll data;
    ListNode *next;

    ListNode (int x)
    {
        data = x;
        next = NULL;
    }
};

ListNode* deleteMiddleNode(ListNode* head) {
   if (head == NULL) {
      return NULL;
   }
   if (head->next == NULL) {
      delete head;
      return NULL;
   }
   ListNode* slow_ptr = head;
   ListNode* fast_ptr = head;
   ListNode* prev;
   while (fast_ptr != NULL && fast_ptr->next != NULL) {
      fast_ptr = fast_ptr->next->next;
      prev = slow_ptr;
      slow_ptr = slow_ptr->next;
   }
   prev->next = slow_ptr->next;
   delete slow_ptr;
   return head;
}

void print(ListNode *head)
{
    while(head != NULL)
    {
        cout<< head->data << " ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    eff;
    int n;
    cin>>n;
    int data;
    cin>>data;
    ListNode *head = new ListNode(data);
    ListNode *temp = head;
    for(int i =0; i<n-1; i++)
    {
        cin>>data;
        temp->next = new ListNode(data);
        temp = temp->next;
    }
    head = deleteMiddleNode(head);
    print(head);
    return 0;
}