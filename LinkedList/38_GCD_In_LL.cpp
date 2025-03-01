// Insert Greatest Common Divisors in Linked List
// Problem link:
// https://leetcode.com/contest/biweekly-contest-110/problems/insert-greatest-common-divisors-in-linked-list/

#include<bits/stdc++.h>
using namespace std;

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
    int gcd(int a, int b)
    {
        if(b == 0)
            return a;
        else
            return gcd(b, a % b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == NULL) return head;
        ListNode *temp = head;
        while(head->next != NULL){
            ListNode *left = head;
            ListNode *right = head->next;
            ListNode *middle = new ListNode(gcd(head->val, head->next->val));
            middle->next = right;
            left->next = middle;
            head = right;
        }
        return temp;
    }
};