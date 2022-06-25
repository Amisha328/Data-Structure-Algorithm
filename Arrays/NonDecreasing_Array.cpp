// Non-decreasing Array
// Problem link:
// https://leetcode.com/problems/non-decreasing-array/
// https://www.codingninjas.com/codestudio/problems/non-decreasing-array_699920?leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        for(int i = 0; i < nums.size()-1; i++)
        {
            // preceeding number is greater than the next number
            if(nums[i] > nums[i+1])
            {
                // prev element of current is greater than the next to current
                // then to make it ascending we change the next element value to current
                if(i-1 >= 0 && nums[i-1] > nums[i+1])
                    nums[i+1] = nums[i];
                // to make it ascending we change the current element value with next element
                else
                    nums[i] = nums[i+1];
                
                // if descending order gets true at most once we break
                break;
            }
            
        }
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i] > nums[i+1])
                return false;
        }
        return true;
    }
};