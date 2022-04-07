// Merge two sorted linked lists
// https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1
// https://leetcode.com/problems/merge-two-sorted-lists/
// https://www.codingninjas.com/codestudio/problems/merge-two-sorted-linked-lists_800332?leftPanelTab=1


#include<iostream>
using namespace std;


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};


// // ################################### MAIN LOGIC ########################################################


// TC -> O(N+M)  | SC->O(1)
Node* sortedMerge(Node* a, Node* b)  
{  
    if(a == NULL) return a;
    if(b == NULL) return b;
    
    Node *head = NULL, *tail = NULL;
    
    if(a->data <= b->data)
    {
        head = tail = a;
        a = a->next;
    }
    else
    {
        head = tail = b;
        b = b->next;
    }
    
    while( a != NULL && b != NULL)
    {
        if(a->data <= b->data)
        {
            tail->next = a;
            tail = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }
    
    if(a == NULL)
        tail->next = b;
    else
        tail->next = a;
    
    return head;
}  

// // #############################################################################################

// Part of GFG compiler

void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


int main()
{
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    return 0;
}

