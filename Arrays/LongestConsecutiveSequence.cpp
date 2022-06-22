// Longest Consecutive Sequence
// Problem link:
// https://leetcode.com/problems/longest-consecutive-sequence/
// https://rb.gy/9v6n5w

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> num_set;
        for(auto x: nums)
            num_set.insert(x);
        
        int longestSequence = 0;
        for(auto x: num_set)
        {
            if(num_set.find(x-1) == num_set.end())
            {
                int curr_num = x;
                int curr_sequence = 1;
                
                while(num_set.find(curr_num+1) != num_set.end())
                {
                    curr_num++;
                    curr_sequence++;
                }
                
                longestSequence = max(longestSequence, curr_sequence);
            }
        }
        return longestSequence;
    }
};