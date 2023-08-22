// Double a Number Represented as a Linked List
// Problem link:
// https://leetcode.com/contest/weekly-contest-358/problems/double-a-number-represented-as-a-linked-list/

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
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        vector<int> arr;
        while(head != NULL){
            arr.push_back(head->val);
            head = head->next;
        }
        /*
        Explanation:
        numbers are from 1 to 9 and if we multiply any digit with 2 (i.e., 9 * 2 = 18) the max carry that we can get
        is 1. Hence there can be a carry of 0 or 1 only.
        */
        int n = arr.size();
        int carry = 0;;
        for(int i = n-1; i >= 0; i--) {
            arr[i] *= 2;
            arr[i] += carry;
            // if arr[i] = 18 so 1 becomes carry and 18-10 = 8 is the base number . Hence, arr[i] = 8
            if(arr[i] >= 10) {
                arr[i] -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
        }
        // for(int i = 0; i < n; i++){
        //     cout<<arr[i]<<" ";
        // }

       // if at the end a carry of 1 is obtained insert it manually at the start of the LinkedList
       // if no carry is there then arr[0] will be the head node.
       ListNode *newHead, *temp;
        if(carry){ 
            newHead = new ListNode(1);
            newHead->next = new ListNode(arr[0]);
            temp = newHead->next;
        }
        else{
            newHead = new ListNode(arr[0]);
            temp = newHead;
        }
        
        for(int i = 1; i < arr.size(); i++){
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        
        return newHead;
    }
};