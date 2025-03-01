// Check if Array is Good
// Problem link:
// https://leetcode.com/contest/biweekly-contest-109/problems/check-if-array-is-good/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n == 1) return false;
        if(nums[n-1] != n-1 || nums[n-1] != nums[n-2]) return false;
        int x = nums[n-1]-1;
        for(int i = nums.size()-3; i >= 0; i--){
            if(nums[i] !=  x) return false;
            else x--;
        }
        return true;
    }
};

/*
Test Case:

[2, 1, 3]
[1, 3, 3, 2]
[1, 1]
[3, 4, 4, 1, 2, 1]
[1]
[1, 2]
[9, 9]

false
true
true
false
false
false
false

*/

