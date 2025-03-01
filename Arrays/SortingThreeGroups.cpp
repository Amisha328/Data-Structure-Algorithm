// Sorting Three Groups
// Problem link:
// https://leetcode.com/problems/sorting-three-groups/submissions/

/*
Intuition
Find all possibility by partition method
[0 - i) -> make them part of group 1
[i - j) -> make them part of group 2
[j - n) -> make them part of group 3
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOps(int i, int j, vector<int>& nums) {
        int count = 0;
        for(int x = 0; x < i; x++) {
            // if the value at x is not 1, change value at arr[x] to group 1.
            if(nums[x] != 1) count++;
        }
        for(int x = i; x < j; x++) {
             // if the value at x is not 2, change value at arr[x] to group 2.
            if(nums[x] != 2) count++;
        }
        for(int x = j; x < nums.size(); x++) {
             // if the value at x is not 3, change value at arr[x] to group 3.
            if(nums[x] != 3) count++;
        }
        return count;
    }
    int minimumOperations(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size(); 
        for(int i = 0 ; i <= n; i++) {
            for(int j = i; j <= n; j++) {
                ans = min(ans, minOps(i, j, nums));
            }
        }
        return ans;
    }
};