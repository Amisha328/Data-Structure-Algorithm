// Intersection Point in Y Shapped Linked Lists
// https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1/#
// https://leetcode.com/problems/intersection-of-two-linked-lists/ 
// https://www.codingninjas.com/codestudio/problem-details/intersection-of-linked-list_630457

#include<bits/stdc++.h>
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


// TC -> O(N+M) | SC->O(1)
int intersectPoint(Node* head1, Node* head2)
{
        if(head1 == NULL && head2 == NULL) return -1;
        
        Node *dummy1 = head1, *dummy2 = head2;
        
        // dummy node will only meet at intersection or at NULL when there is no intersection
        while(dummy1 != dummy2)
        {
            (dummy1 == NULL)? dummy1 = head2 : dummy1 = dummy1->next;
            (dummy2 == NULL)? dummy2 = head1 : dummy2 = dummy2->next;
        }
        
     return dummy1->data;
}

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

int main()
{
          int n1,n2,n3;
          cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    return 0;
}


