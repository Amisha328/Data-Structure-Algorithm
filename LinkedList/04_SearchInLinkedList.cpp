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

int iterativeSearchInLinkedList(ListNode *head, ll x)
{
    int pos = 0;
    while(head != NULL)
    {
        pos++;
        if(head->data == x)
        {
            return pos;
        }

        head = head->next;
    }

    return -1;
}

int recursiveSearchInLinkedList(ListNode *head, ll x)
{
    if(head == NULL) return -1;
    if(head->data == x) return 1;
    int res = recursiveSearchInLinkedList(head->next, x);
    if(res == -1) return -1;
    else return res + 1;
}

signed main(){
    eff;
    
    ListNode *head = new ListNode(20);
    head->next = new ListNode(30);
    head->next->next = new ListNode(40);
    head->next->next->next = new ListNode(50);

    int pos1 = iterativeSearchInLinkedList(head, 30);
    int pos2 = recursiveSearchInLinkedList(head, 40);
    cout << pos1 << " " << pos2 << endl;

    return 0;
}