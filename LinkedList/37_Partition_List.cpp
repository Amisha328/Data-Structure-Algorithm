// Partition List
// Problem link:
// https://leetcode.com/problems/partition-list/
// https://practice.geeksforgeeks.org/problems/partition-a-linked-list-around-a-given-value/1


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

// TC-> O(N)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *leftHead = new ListNode(0);
        ListNode *rightHead = new ListNode(0);
        ListNode *left = leftHead, *right = rightHead;
        while(head != NULL){
            if(head->val < x){
                left->next = head;
                left = left->next;
            }
            else if(head->val >= x){
                right->next = head;
                right = right->next;
            }
            head = head->next;
        }
        right->next = NULL;
        left->next = rightHead->next;
        return leftHead->next;
    }
};