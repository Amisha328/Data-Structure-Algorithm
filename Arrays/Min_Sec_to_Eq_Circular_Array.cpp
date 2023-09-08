// Minimum Seconds to Equalize a Circular Array
// Problem link:
// https://leetcode.com/contest/biweekly-contest-110/problems/minimum-seconds-to-equalize-a-circular-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size();
        // assuming all numbers are different
        int min_time = n-1;
        
        unordered_map<int,vector<int>> mp;
        
         // store all indexs of each number
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]].push_back(i);
        
        for(auto it: mp){
            
            // store all the indexes of each distinct numbers
            vector<int> v = it.second;
            int len = v.size();
            // stores the distance between the last and first index postion in a circular manner.
            int max_time = (n-1) - (v[len-1] - v[0]);

            for(int i = 1; i < len; i++){
                max_time = max(max_time, v[i] - v[i-1] - 1);
            }
            min_time = min(min_time, max_time);
        }
        return (min_time+1)/2;
    }
};