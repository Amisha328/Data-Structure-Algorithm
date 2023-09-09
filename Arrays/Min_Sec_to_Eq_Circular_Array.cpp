// Minimum Seconds to Equalize a Circular Array
// Problem link:
// https://leetcode.com/contest/biweekly-contest-110/problems/minimum-seconds-to-equalize-a-circular-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size();
        // Assuming all numbers are different
        int min_time = n-1;
        
        unordered_map<int,vector<int>> mp;
        
         // store all indexes of each number
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]].push_back(i);
        
        for(auto it: mp){
            
            // store all the indexes of each distinct number
            vector<int> v = it.second;
            int len = v.size();
            // stores the distance between the last and first index positions in a circular manner.
            int max_time = (n-1) - (v[len-1] - v[0]);

            for(int i = 1; i < len; i++){
                max_time = max(max_time, v[i] - v[i-1] - 1);
            }
            min_time = min(min_time, max_time);
        }
        // specially to handle the odd case - 
        // like if there are 5 elements between two elements then max time to change them is 
        // i _ _ _ _ _ j -> time: 1 sec => i 1 _ _ _ 1 j
        //                  time: 2 sec => i 1 2 _ 2 1 j
        //                  time: 3 sec => i 1 2 3 2 1 j
        // Total time : 3 sec 
        // So, to get this 3 sec for 5 elements => (5+1)/2 = 3 sec.
        return (min_time+1)/2;
    }
};
