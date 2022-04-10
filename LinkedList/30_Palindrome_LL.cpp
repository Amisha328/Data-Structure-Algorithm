// Check if Linked List is Palindrome
// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1#
// https://leetcode.com/problems/palindrome-linked-list/
// https://www.codingninjas.com/codestudio/problems/palindrom-linked-list_799352?leftPanelTab=0


#include <bits/stdc++.h>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


// TC - > O(n) | SC-> O(1)
class Solution{
    public:
    Node *reverse(Node *head)
    {
        if(head == NULL || head->next == NULL) return head;
        
        Node *curr = head, *prev = NULL, *nxt = NULL;
        while(curr)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head == NULL) return true;
        
        Node * slow = head, *fast = head;
        // Find the middle of LL
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // reverse the second half of the LL
        Node *rev = reverse(slow->next);
        Node *curr = head;
        while(rev != NULL)
        {
            if(curr->data != rev->data)
                return false;
            
            curr = curr->next;
            rev = rev->next;
        }
        return true;
    }
};

int main()
{
  int i,n,l,firstdata;
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
    cout<<obj.isPalindrome(head)<<endl;

    return 0;
}
