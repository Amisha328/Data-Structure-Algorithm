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

ll middleNode(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

signed main(){
    eff;
    
    ListNode *head = new ListNode(20);
    head->next = new ListNode(30);
    head->next->next = new ListNode(40);
    head->next->next->next = new ListNode(50);
    head->next->next->next->next = new ListNode(60);
    
    ll mid_val = middleNode(head);
    cout<<mid_val<<endl;

    return 0;
}

// Time Complexity: O(n)