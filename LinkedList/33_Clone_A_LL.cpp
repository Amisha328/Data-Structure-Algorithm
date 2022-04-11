// Clone a Linked List with next and random pointer
// Problem Link:
// https://leetcode.com/problems/copy-list-with-random-pointer/
// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
// https://www.codingninjas.com/codestudio/problem-details/clone-linked-list-with-random-pointer_873376

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    /*
    // Naive solution: TC->O(n) | SC->O(n)
    Node* copyRandomList(Node* head) {
        
        Node *p =head;
        map<Node*,Node*> mp;
         
        Node *temp = new Node(-1);
        Node *q = temp;
        
        while(p!=NULL)
        {
            Node *temp = new Node(p->val);
            q->next = temp;
            q = q->next;
            mp[p] = q;
            p = p -> next;
        }
        
        p = head;
        q = temp->next;
        
        while(p!=NULL)
        {
            Node *r = p->random;
            q->random = mp[r];
            
            p=p->next;
            q=q->next;
        }
        
        return temp->next;
    }
    */
    
    // Efficient Solution:  TC->O(n) | SC->O(1)
    Node* copyRandomList(Node* head) {
        
        // First step is to make copy of each node,
        // and link them together side-by-side in a single list.
        
        Node *iter = head, *front = head;
        
        while(iter != NULL)
        {
            front = iter->next;
            Node *copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;
            iter = front;
        }
        
        // Second step is to assign random pointers for the copy nodes.
        iter = head;
        while(iter != NULL)
        {
            if(iter->random != NULL)
                iter->next->random = iter->random->next;
            
            iter = iter->next->next;  // points to next original node
        }
        
        // Third step is to restore the original Linkedlist, and extract the copy Linkedlist.
        iter = head, front = head;
        Node *dummyHead = new Node(0);
        Node *copy = dummyHead;
        while(iter != NULL)
        {
            front = iter->next->next;
            
            // extract the copy Linkedlist
            copy->next = iter->next;
            
            // restore the original Linkedlist
            iter->next = front;
            
            copy = copy->next;
            iter = front;
            
        }
        return dummyHead->next;
    }
};