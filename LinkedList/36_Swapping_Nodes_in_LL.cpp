// Swapping Nodes in a Linked List
// Problem link:
// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *fast = head, *slow = head, *first;
        k -= 1; // we reduce k by 1 as we fast is initialized head initially 
        while(k--)
        {
            fast = fast->next;
        }
        
        first = fast; // stores the kth node from the beginning
        
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next; // now tye slow will point to the kth node from the end
            fast = fast->next;
        }
        
        swap(slow->val, first->val);
        
        return head;
    }
};