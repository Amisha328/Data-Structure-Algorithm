// Given the head of a linked list, rotate the list to the right by k places.

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

// TC-> O(N) + O(N-(k%N)) = O(N) | SC-> O(1)
ListNode* rotateRight(ListNode* head, int k) 
{
        // edge cases 
        if (head == NULL || head->next == NULL || k == 0) return head;
        
        // compute the length
        ListNode *cur = head;
        int len = 1;
        while (cur->next)
        {
            len++;
            cur = cur->next;
        }
            
        // go till that node
        cur->next = head;
        k = k % len; 
        k = len - k;
        while (k--) 
            cur = cur->next;
        
        // make the node head and break connection 
        head = cur->next;
        cur->next = NULL;
        
        
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

int main()
{
    eff;
    int n;
    cin>>n;
    int k;
    cin>>k;
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
    head = rotateRight(head, k);
    print(head);
    return 0;
}