// Split Linked List in Parts
// https://leetcode.com/problems/split-linked-list-in-parts/description

#include<bits/stdc++.h>
using namespace std;
#define eff ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long


// TC: O(N)
// SC: O(K)

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int sizeLL = 0;
        ListNode *curr = head;
        while(curr){
            sizeLL++;
            curr = curr->next;
        }
         // minimum size for the k parts
        int ques = sizeLL/k;

        // Remaining nodes after splitting the k parts evenly.
        // These will be distributed to the first (size % k) nodes
        int rem = sizeLL%k;

        vector<ListNode*> ans(k, NULL);
        int idx = 0;
        curr = head;
        while(curr != NULL){
            ListNode *newHead = curr;
            ListNode *prev = newHead;
            int splitSize  = ques; 

            // calculate size of i-th part
            if(rem > 0) {
                rem--;
                splitSize++;
            }
            for(int i = 1; i <= splitSize; i++){
                prev = curr;
                curr = curr->next;
            }
            // cut off the rest of linked list
            if(prev != NULL) prev->next = NULL;
            ans[idx++] = newHead;
        }
        return ans;
    }
};
